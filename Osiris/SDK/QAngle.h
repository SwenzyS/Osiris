#pragma once

struct QAngle final {
    constexpr QAngle& operator-(const QAngle& v) noexcept
    {
        pitch -= v.pitch;
        yaw -= v.yaw;
        roll -= v.roll;
        return *this;
    }

    void normalize() noexcept
    {
        if (pitch != pitch)
            pitch = 0.0f;
        if (yaw != yaw)
            yaw = 0.0f;
        if (roll != roll)
            roll = 0.0f;

        if (pitch > 89.f)
            pitch = 89.f;
        if (pitch < -89.f)
            pitch = -89.f;

        while (yaw > 180)
            yaw -= 360;
        while (yaw <= -180)
            yaw += 360;

        if (yaw > 180.f)
            yaw = 180.f;
        if (yaw < -180.f)
            yaw = -180.f;

        roll = 0;
    }

    float pitch;
    float yaw;
    float roll;
};
