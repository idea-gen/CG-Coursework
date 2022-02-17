//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "Primitive.h"
#include "visual/Viewport.h"
#include <memory>
#include <utility>
#include <vector>

class Clipper {
private:
    Primitive _primitive;
    Viewport _viewport;
    static double clipCoefficient(double in, double out, double bound) {
        auto sign = in < out ? -1. : 1.;
        auto cut = sign * (in - bound);
        static auto eps = 1. / 64.;
        auto len = std::abs(std::abs(in - out) < eps ? 2 * in : out - in);
        return cut / len;
    }
    static Vector<3, double> clipPoint(Vector<3, double> in, Vector<3, double> out, int axisIndex, double bound) {
        auto t = clipCoefficient(in[axisIndex], out[axisIndex], bound);
        return Vector<3, double>(in.x + (out.x - in.x) * t,
                               in.y + (out.y - in.y) * t,
                               in.z + (out.z - in.z) * t);
    }
    static std::vector<std::array<Vertex, 3>> clipPair(const Vector<3, double>& in0,
                                             const Vector<3, double>& in1,
                                             const Vector<3, double>& out, int axisIndex, double bound) {
        auto clip0 = clipPoint(in0, out, axisIndex, bound);
        auto clip1 = clipPoint(in1, out, axisIndex, bound);
        return {{in0, clip0, clip1},
                {in0, in1, clip1}};
    }
    static std::vector<std::array<Vertex, 3>> clipSingle(const Vector<3, double>& in,
                                             const Vector<3, double>& out0,
                                             const Vector<3, double>& out1, int axisIndex, double bound) {
        auto clip0 = clipPoint(in, out0, axisIndex, bound);
        auto clip1 = clipPoint(in, out1, axisIndex, bound);
        return {{in, clip0, clip1}};
    }
    static std::vector<Primitive> clipFunc(const Primitive& primitive, int axisIndex, double bound,
                                    const std::function<bool(const double&, const double&)>& comp) {
        auto vertices = primitive.vertices();
        auto test = [&](int vertexIndex) {
            return comp(vertices[vertexIndex][axisIndex], bound);
        };
        auto test0 = test(0), test1 = test(1), test2 = test(2);
        auto& v0 = vertices[0], v1 = vertices[1], v2 = vertices[2];
        auto packPair = [&](const Vector<3, double>& in0,
                const Vector<3, double>& in1, const Vector<3, double>& out) {
            auto packedVertices = clipPair(in0, in1, out, axisIndex, bound);
            std::vector<Primitive> result;
            for (const auto& pack : packedVertices)
                result.emplace_back(pack, primitive.normal());
            return result;
        };
        auto packSingle = [&](const Vector<3, double>& in,
                            const Vector<3, double>& out0, const Vector<3, double>& out1) {
            auto packedVertices = clipSingle(in, out0, out1, axisIndex, bound);
            std::vector<Primitive> result;
            for (const auto& pack : packedVertices)
                result.emplace_back(pack, primitive.normal());
            return result;
        };
        if (test0) {
            if (test1) {
                if (test2) {
                    return {primitive};
                }
                else {

                    return packPair(v0, v1, v2);
                }
            }
            else {
                if (test2) {
                    return packPair(v0, v2, v1);
                }
                else {
                    return packSingle(v0, v1, v2);
                }
            }
        }
        else {
            if (test1) {
                if (test2) {
                    return packPair(v1, v2, v0);
                }
                else {
                    return packSingle(v1, v0, v2);
                }
            }
            else {
                if (test2) {
                    return packSingle(v2, v0, v1);
                }
                else {
                    return {};
                }
            }
        }
        throw std::runtime_error("Near clipping failed");
    }
public:
    explicit Clipper(Primitive primitive, Viewport viewport)
    : _primitive(std::move(primitive)), _viewport(viewport) {};
    [[nodiscard]] std::vector<Primitive> clip() const {
        std::vector<Primitive> result;
        auto le = std::less_equal<double>{};
        auto ge = std::greater_equal<double>{};
        auto nearClipped = clipFunc(_primitive,2,
                                    _viewport.nearDepth(), ge);
        for (const auto& nClipped : nearClipped) {
            auto farClipped = clipFunc(nClipped,2,
                                       _viewport.farDepth(), le);
            for (const auto& fClipped : farClipped) {
                auto bottomClipped = clipFunc(fClipped, 1,
                                           _viewport.width0(), ge);
                for (const auto& bClipped : bottomClipped) {
                    auto topClipped = clipFunc(bClipped, 1,
                                               _viewport.width0() + _viewport.height(), le);
                    for (const auto& tClipped : topClipped) {
                        auto leftClipped = clipFunc(tClipped, 0,
                                                    _viewport.height0(), ge);
                        for (const auto& lClipped : leftClipped) {
                            auto rightClipped = clipFunc(lClipped, 0,
                                                         _viewport.height0() + _viewport.height(), le);
                            result.insert(result.begin(), rightClipped.begin(), rightClipped.end());
                        }
                    }
                }
            }
        }
        return result;
    };
};


