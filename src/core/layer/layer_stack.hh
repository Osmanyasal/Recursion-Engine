#ifndef RECURSION_ENGINE__SRC__CORE__LAYER__LAYER_STACK_HH
#define RECURSION_ENGINE__SRC__CORE__LAYER__LAYER_STACK_HH

#include <layer.hh>
#include <utils.hh>
#include <vector>
namespace Recursion::core::layer
{
    class LayerStack
    {
    public:
        LayerStack(){};
        virtual ~LayerStack()
        {
            for (Layer *layer : layers)
                delete layer;
            layers.clear();
        };

        inline int get_size() { return layers.size(); }
        void add_layer(Layer *layer);
        bool remove_layer(Layer *layer);
        const Layer* get_layer(const std::string &name);
         bool disable_layer(Layer *layer);

        std::vector<Layer *>::iterator begin() { return layers.begin(); }
        std::vector<Layer *>::iterator end() { return layers.end(); }
        std::vector<Layer *>::reverse_iterator rbegin() { return layers.rbegin(); }
        std::vector<Layer *>::reverse_iterator rend() { return layers.rend(); }

        std::vector<Layer *>::const_iterator begin() const { return layers.begin(); }
        std::vector<Layer *>::const_iterator end() const { return layers.end(); }
        std::vector<Layer *>::const_reverse_iterator rbegin() const { return layers.rbegin(); }
        std::vector<Layer *>::const_reverse_iterator rend() const { return layers.rend(); }

    private:
        std::vector<Layer *> layers;
    };
} // namespace Recursion::core::layer

#endif