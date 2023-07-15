#include <layer_stack.hh>

namespace Recursion::core::layer
{
    void LayerStack::add_layer(Layer *layer)
    {
        if (OPT_LIKELY(layer != nullptr))
            layers.push_back(layer);
        else
        {
            REC_CORE_WARN("layer cannot be added since it is null");
        }
    }
    const Layer* LayerStack::get_layer(const std::string &name)
    {
        for (auto iter = this->layers.begin(); iter != this->layers.end(); iter++)
        {
            if ((*iter)->get_name() == name)
                return *iter;
        }
        return nullptr;
    }

    bool LayerStack::remove_layer(Layer *layer)
    {
        if (OPT_UNLIKELY(layer == nullptr))
        {
            REC_CORE_WARN("layer cannot disabled since it is null");
            return false;
        }
        auto loc = std::find(layers.begin(), layers.end(), layer);
        if (OPT_LIKELY(loc != layers.end()))
        {
            layers.erase(loc);
        }
        return true;
    }
    bool LayerStack::disable_layer(Layer *layer)
    {
        if (OPT_UNLIKELY(layer == nullptr))
        {
            REC_CORE_WARN("layer cannot disabled since it is null");
        }
        else if (OPT_LIKELY(std::find(layers.begin(), layers.end(), layer) != layers.end()))
        {
            layer->set_is_active(false);
            return true;
        }
        return false;
    }
} // namespace Recursion::core::layer
