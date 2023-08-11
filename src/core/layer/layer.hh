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
		inline Layer(const std::string &name = "Layer") : m_DebugName{name}, id{generateGUID()}, m_is_active{true} {}
		virtual ~Layer() { REC_CORE_INFO("layer {} destroyed!", m_DebugName); };

		virtual void on_attach() {}
		virtual void on_detach() {}
		virtual void on_update(float delta_time) {}
		virtual void on_event(events::Event &event) {}

		virtual std::string to_string() const
		{
			std::stringstream out;
			out << "Layer("
				<< "id=" << id.substr(0, CONF__LOG__PRINT_GUID_LENGTH) << ", debug_name=" << m_DebugName << std::endl;
			return out.str();
		}
		const std::string &get_name() const { return m_DebugName; }
		inline void is_active(bool is_active)
		{
			this->m_is_active = is_active;
			REC_CORE_INFO("layer is set to active : {} !", is_active);
		}
		inline bool is_active() { return this->m_is_active; }

	protected:
		std::string m_DebugName;
		std::string id;
		bool m_is_active;
	};

} // namespace Recursion::core::layer
#endif