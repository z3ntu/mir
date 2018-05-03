/*
 * AUTOGENERATED - DO NOT EDIT
 *
 * This header is generated by wrapper_generator.cpp from wlr-layer-shell-unstable-v1.xml
 * To regenerate, run the “refresh-wayland-wrapper” target.
 */

#ifndef MIR_FRONTEND_WAYLAND_WLR_LAYER_SHELL_UNSTABLE_V1_XML_WRAPPER
#define MIR_FRONTEND_WAYLAND_WLR_LAYER_SHELL_UNSTABLE_V1_XML_WRAPPER

#include <experimental/optional>
#include <boost/throw_exception.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include "wlr-layer-shell-unstable-v1.h"

#include "mir/fd.h"
#include "mir/log.h"

namespace mir
{
namespace frontend
{
namespace wayland
{
class LayerShellV1
{
protected:
    LayerShellV1(struct wl_display* display, uint32_t max_version)
        : global{wl_global_create(display, &zwlr_layer_shell_v1_interface, max_version,
                                  this, &LayerShellV1::bind_thunk)},
            max_version{max_version}
    {
        if (global == nullptr)
        {
            BOOST_THROW_EXCEPTION((std::runtime_error{
                "Failed to export zwlr_layer_shell_v1 interface"}));
        }
    }
    virtual ~LayerShellV1()
    {
        wl_global_destroy(global);
    }

    virtual void bind(struct wl_client* client, struct wl_resource* resource) { (void)client; (void)resource; }
    virtual void get_layer_surface(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* surface, std::experimental::optional<struct wl_resource*> const& output, uint32_t layer, std::string const& namespace) = 0;

    struct wl_global* const global;
    uint32_t const max_version;

private:
    static void get_layer_surface_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* surface, struct wl_resource* output, uint32_t layer, char const* namespace)
    {
        auto me = static_cast<LayerShellV1*>(wl_resource_get_user_data(resource));
        std::experimental::optional<struct wl_resource*> output_resolved;
        if (output != nullptr)
        {
            output_resolved = output;
        }
        try
        {
            me->get_layer_surface(client, resource, id, surface, output_resolved, layer, namespace);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerShellV1::get_layer_surface() request");
        }
    }

    static void bind_thunk(struct wl_client* client, void* data, uint32_t version, uint32_t id)
    {
        auto me = static_cast<LayerShellV1*>(data);
        auto resource = wl_resource_create(client, &zwlr_layer_shell_v1_interface,
                                           std::min(version, me->max_version), id);
        if (resource == nullptr)
        {
            wl_client_post_no_memory(client);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, get_vtable(), me, nullptr);
        try
        {
          me->bind(client, resource);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerShellV1::bind() request");
        }
    }

    static inline struct zwlr_layer_shell_v1_interface const* get_vtable()
    {
        static struct zwlr_layer_shell_v1_interface const vtable = {
            get_layer_surface_thunk,
        };
        return &vtable;
    }
};


class LayerSurfaceV1
{
protected:
    LayerSurfaceV1(struct wl_client* client, struct wl_resource* parent, uint32_t id)
        : client{client},
          resource{wl_resource_create(client, &zwlr_layer_surface_v1_interface, wl_resource_get_version(parent), id)}
    {
        if (resource == nullptr)
        {
            wl_resource_post_no_memory(parent);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, get_vtable(), this, &resource_destroyed_thunk);
    }
    virtual ~LayerSurfaceV1() = default;

    virtual void set_size(uint32_t width, uint32_t height) = 0;
    virtual void set_anchor(uint32_t anchor) = 0;
    virtual void set_exclusive_zone(int32_t zone) = 0;
    virtual void set_margin(int32_t top, int32_t right, int32_t bottom, int32_t left) = 0;
    virtual void set_keyboard_interactivity(uint32_t keyboard_interactivity) = 0;
    virtual void get_popup(struct wl_resource* popup) = 0;
    virtual void ack_configure(uint32_t serial) = 0;
    virtual void destroy() = 0;

    struct wl_client* const client;
    struct wl_resource* const resource;

private:
    static void set_size_thunk(struct wl_client*, struct wl_resource* resource, uint32_t width, uint32_t height)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_size(width, height);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::set_size() request");
        }
    }

    static void set_anchor_thunk(struct wl_client*, struct wl_resource* resource, uint32_t anchor)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_anchor(anchor);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::set_anchor() request");
        }
    }

    static void set_exclusive_zone_thunk(struct wl_client*, struct wl_resource* resource, int32_t zone)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_exclusive_zone(zone);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::set_exclusive_zone() request");
        }
    }

    static void set_margin_thunk(struct wl_client*, struct wl_resource* resource, int32_t top, int32_t right, int32_t bottom, int32_t left)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_margin(top, right, bottom, left);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::set_margin() request");
        }
    }

    static void set_keyboard_interactivity_thunk(struct wl_client*, struct wl_resource* resource, uint32_t keyboard_interactivity)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_keyboard_interactivity(keyboard_interactivity);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::set_keyboard_interactivity() request");
        }
    }

    static void get_popup_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* popup)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->get_popup(popup);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::get_popup() request");
        }
    }

    static void ack_configure_thunk(struct wl_client*, struct wl_resource* resource, uint32_t serial)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->ack_configure(serial);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::ack_configure() request");
        }
    }

    static void destroy_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing LayerSurfaceV1::destroy() request");
        }
    }

    static void resource_destroyed_thunk(wl_resource* resource)
    {
        delete static_cast<LayerSurfaceV1*>(wl_resource_get_user_data(resource));
    }

    static inline struct zwlr_layer_surface_v1_interface const* get_vtable()
    {
        static struct zwlr_layer_surface_v1_interface const vtable = {
            set_size_thunk,
            set_anchor_thunk,
            set_exclusive_zone_thunk,
            set_margin_thunk,
            set_keyboard_interactivity_thunk,
            get_popup_thunk,
            ack_configure_thunk,
            destroy_thunk,
        };
        return &vtable;
    }
};


}
}
}

#endif // MIR_FRONTEND_WAYLAND_WLR_LAYER_SHELL_UNSTABLE_V1_XML_WRAPPER
