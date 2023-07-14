#ifndef RECURSION_ENGINE__SRC__CORE__LAYER__LAYER_HH
#define RECURSION_ENGINE__SRC__CORE__LAYER__LAYER_HH

#include <iostream>
#include <event_core.hh>
#include <utils.hh>
#include <sstream>

namespace Recursion::core::layer
{
	namespace events = Recursion::core::events;
	class Layer
	{

	public:
		inline Layer(const std::string &name = "Layer") : m_DebugName{name}, id{generateGUID()}, is_active{false} {}
		virtual ~Layer() = default;

		virtual void on_attach() {}
		virtual void on_detach() {}
		// virtual void OnUpdate(Timestep ts) {}
		virtual void on_imgui_render() {}
		virtual void on_event(events::Event &event) {}
		virtual std::string to_string() const
		{
			std::stringstream out;
			out << "Layer("
				<< "id=" << id.substr(0, CONF__LOG__PRINT_GUID_LENGTH) << ", debug_name=" << m_DebugName << std::endl;
			return out.str();
		}
		const std::string &get_name() const { return m_DebugName; }
		void set_is_active(bool is_active){
			this->is_active = is_active;
		}

	protected:
		std::string m_DebugName;
		std::string id;
		bool is_active;
	};

} // namespace Recursion::core::layer
#endif