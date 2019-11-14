#include "Point3D.h"

#include <cmath>
#include <cfloat>

namespace game_engine_math {
    float DistPointLine(const Point3D &q, const Point3D &p, const Vector3D& v) {
        Vector3D a = CrossProduct(q - p, v);
        return std::sqrt(DotProduct(a, a) / DotProduct(v, v));
    }

    float DistLineLine(const Point3D& p1, const Vector3D& v1,
                       const Point3D& p2, const Vector3D& v2) {
        Vector3D dp = p2 - p1;
        float v1v1 = DotProduct(v1, v1);
        float v2v2 = DotProduct(v2, v2);
        float v1v2 = DotProduct(v1, v2);
        float det = v1v2 * v1v2 - v1v1 * v2v2;
        if(std::fabs(det) > FLT_MIN) {
            det = 1.0f / det;
            float dpv1 = DotProduct(dp, v1);
            float dpv2 = DotProduct(dp, v2);
            float t1 = (v1v2 * dpv2 - v2v2 * dpv1) * det;
            float t2 = (v1v1 * dpv2 - v1v2 * dpv1) * det;
            return Magnitude(dp + v2 * t2 - v1 * t1);
        }
        Vector3D a = CrossProduct(dp, v1);
        return std::sqrt(DotProduct(a, a) / v1v1);
    }
}