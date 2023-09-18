#include <imgui_logger.hh>

ImGuiTextBuffer ImGuiLogger::Buf;
ImGuiTextFilter ImGuiLogger::Filter;
ImVector<int> ImGuiLogger::LineOffsets;
bool ImGuiLogger::ScrollToBottom = true;  

void ImGuiLogger::AddLog(const char *fmt, ...)
{
    int old_size = Buf.size();
    va_list args;
    va_start(args, fmt);
    Buf.appendfv(fmt, args);
    va_end(args);
    for (int new_size = Buf.size(); old_size < new_size; old_size++)
        if (Buf[old_size] == '\n')
            LineOffsets.push_back(old_size);
    ScrollToBottom = true;
}

void ImGuiLogger::Draw()
{
    if (ImGui::Button("Clear"))
        Clear();
    ImGui::SameLine();
    bool copy = ImGui::Button("Copy");
    ImGui::SameLine();
    Filter.Draw("Filter", -100.0f);
    ImGui::Separator();
    ImGui::BeginChild("scrolling");
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 1));
    if (copy)
        ImGui::LogToClipboard();

    if (Filter.IsActive())
    {
        const char *buf_begin = Buf.begin();
        const char *line = buf_begin;
        for (int line_no = 0; line != NULL; line_no++)
        {
            const char *line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;
            if (Filter.PassFilter(line, line_end))
                ImGui::TextUnformatted(line, line_end);
            line = line_end && line_end[1] ? line_end + 1 : NULL;
        }
    }
    else
    {
        ImGui::TextUnformatted(Buf.begin());
    }

    if (ScrollToBottom)
        ImGui::SetScrollHereY(1.0f);
    ScrollToBottom = false;
    ImGui::PopStyleVar();
    ImGui::EndChild();
}