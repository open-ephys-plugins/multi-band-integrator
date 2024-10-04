/*
------------------------------------------------------------------

This file is part of a plugin for the Open Ephys GUI
Copyright (C) 2017 Translational NeuroEngineering Laboratory, MGH

------------------------------------------------------------------

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "MultiBandIntegratorEditor.h"
#include "MultiBandIntegrator.h"

CustomLabel::CustomLabel(Parameter* param) : ParameterEditor(param)
{
    label.addListener(this);
    label.setBounds(0, 0, 40, 15);
    label.setEditable(true);
    addAndMakeVisible(&label);
    setBounds(0, 0, 40, 15);
}

void BackgroundComponent::paint(Graphics& g)
{
    g.setColour( findColour (ThemeColours::componentBackground));
    g.fillRoundedRectangle(120, 25, 130, 65, 3.0f);
    
    g.setColour (findColour (ThemeColours::defaultText));
    g.drawText("low", 125, 12, 40, 10, Justification::centred);
    g.drawText("high", 165, 12, 40, 10, Justification::centred);
    g.drawText("gain", 205, 12, 40, 10, Justification::centred);
    
    g.drawText(CharPointer_UTF8("α"), 108, 32, 50, 10, Justification::left);
    g.drawText(CharPointer_UTF8("β"), 108, 52, 50, 10, Justification::left);
    g.drawText(CharPointer_UTF8("δ"), 108, 72, 50, 10, Justification::left);
}

MultiBandIntegratorEditor::MultiBandIntegratorEditor(GenericProcessor* parentNode)
    : GenericEditor(parentNode)
{
	desiredWidth = 254;

    addSelectedChannelsParameterEditor(Parameter::ParameterScope::STREAM_SCOPE, "Channel", 10, 35);
    ParameterEditor* channelEditor = getParameterEditor("Channel");
    channelEditor->setLayout(ParameterEditor::Layout::nameOnTop);
    channelEditor->setSize(90,34);

    addTextBoxParameterEditor(Parameter::ParameterScope::PROCESSOR_SCOPE, "window_ms", 10, 77);
    ParameterEditor* windowEditor = getParameterEditor("window_ms");
    windowEditor->setLayout(ParameterEditor::Layout::nameOnTop);
    windowEditor->setSize(90,34);
    
    Parameter* param = getProcessor()->getParameter("alpha_low");
    addCustomParameterEditor(new CustomLabel(param), 125, 55);
    param = getProcessor()->getParameter("alpha_high");
    addCustomParameterEditor(new CustomLabel(param), 165, 55);
    param = getProcessor()->getParameter("alpha_gain");
    addCustomParameterEditor(new CustomLabel(param), 205, 55);
    
    param = getProcessor()->getParameter("beta_low");
    addCustomParameterEditor(new CustomLabel(param), 125, 75);
    param = getProcessor()->getParameter("beta_high");
    addCustomParameterEditor(new CustomLabel(param), 165, 75);
    param = getProcessor()->getParameter("beta_gain");
    addCustomParameterEditor(new CustomLabel(param), 205, 75);
    
    param = getProcessor()->getParameter("delta_low");
    addCustomParameterEditor(new CustomLabel(param), 125, 95);
    param = getProcessor()->getParameter("delta_high");
    addCustomParameterEditor(new CustomLabel(param), 165, 95);
    param = getProcessor()->getParameter("delta_gain");
    addCustomParameterEditor(new CustomLabel(param), 205, 95);

    addAndMakeVisible(&backgroundComponent);
    backgroundComponent.setBounds(0, 25, 250, 140);
    backgroundComponent.toBack();
}