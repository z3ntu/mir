/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alexandros Frantzis <alexandros.frantzis@canonical.com>
 */

#ifndef MIR_GRAPHICS_GBM_GBM_DISPLAY_HELPERS_H_
#define MIR_GRAPHICS_GBM_GBM_DISPLAY_HELPERS_H_

#include <cstddef>

#define __GBM__
#include <EGL/egl.h>
#include <gbm.h>
#include <xf86drmMode.h>

namespace mir
{
namespace graphics
{
namespace gbm
{
namespace helpers
{

class DRMHelper
{
public:
    DRMHelper() : fd{-1} {}
    ~DRMHelper() { cleanup(); }

    DRMHelper(const DRMHelper &) = delete;
    DRMHelper& operator=(const DRMHelper&) = delete;

    void setup();

    int fd;

private:
    void cleanup();
};

class KMSHelper {
public:
    KMSHelper()
        : resources{0}, connector{0}, encoder{0}, mode(),
          drm_fd{-1}, saved_crtc{0}
    {
    }

    ~KMSHelper() { cleanup(); }

    KMSHelper(const KMSHelper&) = delete;
    KMSHelper& operator=(const KMSHelper&) = delete;

    void setup(const DRMHelper& drm);

    drmModeRes *resources;
    drmModeConnector *connector;
    drmModeEncoder *encoder;
    drmModeModeInfo mode;

private:
    int drm_fd;
    drmModeCrtc *saved_crtc;

    void cleanup();
};

class GBMHelper
{
public:
    GBMHelper() : device{0}, surface{0} {}
    ~GBMHelper() { cleanup(); }

    GBMHelper(const GBMHelper&) = delete;
    GBMHelper& operator=(const GBMHelper&) = delete;

    void setup(const DRMHelper& drm, uint32_t width, uint32_t height);

    gbm_device* device;
    gbm_surface* surface;

private:
    void cleanup();
};

class EGLHelper
{
public:
    EGLHelper()
        : display(EGL_NO_DISPLAY), config(0),
          context(EGL_NO_CONTEXT), surface(EGL_NO_SURFACE) {}

    ~EGLHelper() { cleanup(); }

    EGLHelper(const EGLHelper&) = delete;
    EGLHelper& operator=(const EGLHelper&) = delete;

    void setup(const GBMHelper& gbm_info);

    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;

private:
    void cleanup();
};

}
}
}
}
#endif /* MIR_GRAPHICS_GBM_GBM_DISPLAY_HELPERS_H_ */
