<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="23008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="dll" Type="Folder">
			<Item Name="ygDLL.dll" Type="Document" URL="../ygDLL.dll"/>
		</Item>
		<Item Name="old version" Type="Folder">
			<Item Name="diffraction pattern v1.5.vi" Type="VI" URL="../diffraction pattern v1.5.vi"/>
		</Item>
		<Item Name="subVI" Type="Folder">
			<Item Name="2d array to file.vi" Type="VI" URL="../2d array to file.vi"/>
			<Item Name="array gen 1.vi" Type="VI" URL="../array gen 1.vi"/>
			<Item Name="bump disorder.vi" Type="VI" URL="../bump disorder.vi"/>
			<Item Name="Calculate CPR.vi" Type="VI" URL="../Calculate CPR.vi"/>
			<Item Name="combine two dist.vi" Type="VI" URL="../combine two dist.vi"/>
			<Item Name="dllparameter.ctl" Type="VI" URL="../dllparameter.ctl"/>
			<Item Name="flat disorder.vi" Type="VI" URL="../flat disorder.vi"/>
			<Item Name="Gen Array.vi" Type="VI" URL="../Gen Array.vi"/>
			<Item Name="gen j disorder.vi" Type="VI" URL="../gen j disorder.vi"/>
			<Item Name="generate Ic distribution.vi" Type="VI" URL="../generate Ic distribution.vi"/>
			<Item Name="get both TA and MQT.vi" Type="VI" URL="../get both TA and MQT.vi"/>
			<Item Name="get escaping rate.vi" Type="VI" URL="../get escaping rate.vi"/>
			<Item Name="getfluxpoint.vi" Type="VI" URL="../getfluxpoint.vi"/>
			<Item Name="graph to file.vi" Type="VI" URL="../graph to file.vi"/>
			<Item Name="Open a Document on Disk.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/browser.llb/Open a Document on Disk.vi"/>
			<Item Name="paramaters2.ctl" Type="VI" URL="../paramaters2.ctl"/>
			<Item Name="Plot J profile.vi" Type="VI" URL="../Plot J profile.vi"/>
			<Item Name="plot offset.vi" Type="VI" URL="../plot offset.vi"/>
			<Item Name="remove last element_2Darray.vi" Type="VI" URL="../remove last element_2Darray.vi"/>
			<Item Name="remove last element_plots.vi" Type="VI" URL="../remove last element_plots.vi"/>
			<Item Name="remove last plot.vi" Type="VI" URL="../remove last plot.vi"/>
			<Item Name="remove one element in array.vi" Type="VI" URL="../remove one element in array.vi"/>
			<Item Name="S-TI-S Josephson junction simulation.rtm" Type="Document" URL="../S-TI-S Josephson junction simulation.rtm"/>
			<Item Name="segment function.vi" Type="VI" URL="../segment function.vi"/>
			<Item Name="Set dll parameter.vi" Type="VI" URL="../Set dll parameter.vi"/>
			<Item Name="set_Ic_sim_parameter.vi" Type="VI" URL="../set_Ic_sim_parameter.vi"/>
			<Item Name="three ramps disorder.vi" Type="VI" URL="../three ramps disorder.vi"/>
			<Item Name="ygdll path.vi" Type="VI" URL="../ygdll path.vi"/>
		</Item>
		<Item Name="support package" Type="Folder">
			<Item Name="Readme.rtf" Type="Document" URL="../Readme.rtf"/>
			<Item Name="S-TI-S_JJ_Simulation Help.chm" Type="Document" URL="../S-TI-S_JJ_Simulation Help.chm"/>
			<Item Name="ygDLL.dll" Type="Document" URL="../../S-TI-S jj simulation c/Release/ygDLL.dll"/>
		</Item>
		<Item Name="test" Type="Folder">
			<Item Name="test dll.vi" Type="VI" URL="../test dll.vi"/>
		</Item>
		<Item Name="disorder study.vi" Type="VI" URL="../disorder study.vi"/>
		<Item Name="Ic distribution simulation.vi" Type="VI" URL="../Ic distribution simulation.vi"/>
		<Item Name="mean and SD.vi" Type="VI" URL="../mean and SD.vi"/>
		<Item Name="S-TI-S JJ Simulation.vi" Type="VI" URL="../S-TI-S JJ Simulation.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Application Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Application Directory.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="ex_CorrectErrorChain.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_CorrectErrorChain.vi"/>
				<Item Name="High Resolution Relative Seconds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/High Resolution Relative Seconds.vi"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_AALPro.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALPro.lvlib"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_Gmath.lvlib" Type="Library" URL="/&lt;vilib&gt;/gmath/NI_Gmath.lvlib"/>
				<Item Name="subDisplayMessage.vi" Type="VI" URL="/&lt;vilib&gt;/express/express output/DisplayMessageBlock.llb/subDisplayMessage.vi"/>
				<Item Name="subTimeDelay.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/TimeDelayBlock.llb/subTimeDelay.vi"/>
				<Item Name="System Exec.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/System Exec.vi"/>
				<Item Name="Write Delimited Spreadsheet (DBL).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet (DBL).vi"/>
				<Item Name="Write Delimited Spreadsheet (I64).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet (I64).vi"/>
				<Item Name="Write Delimited Spreadsheet (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet (string).vi"/>
				<Item Name="Write Delimited Spreadsheet.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet.vi"/>
				<Item Name="Write Spreadsheet String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Spreadsheet String.vi"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Property Name="NI.SortType" Type="Int">3</Property>
			<Item Name="S-TI-S JJ Simulation" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{E43DC9D0-FAB8-42ED-9773-3320433801AD}</Property>
				<Property Name="App_INI_GUID" Type="Str">{D68F3105-342C-4A10-B590-D2898F8A7B38}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_serverType" Type="Int">1</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{E1E393B9-226A-46B7-B844-5A28F480DF57}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">S-TI-S JJ Simulation</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/S-TI-S JJ Simulation</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{06DCD04C-93FD-44E0-8FA1-300EE9723308}</Property>
				<Property Name="Bld_supportedLanguage[0]" Type="Str">English</Property>
				<Property Name="Bld_supportedLanguageCount" Type="Int">1</Property>
				<Property Name="Bld_version.build" Type="Int">47</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">S-TI-S JJ Simulation.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/S-TI-S JJ Simulation/S-TI-S JJ Simulation.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/S-TI-S JJ Simulation</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{6E6942CF-B470-400B-9A20-3ADF9F05738A}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/old version/diffraction pattern v1.5.vi</Property>
				<Property Name="Source[1].properties[0].type" Type="Str">Show menu bar</Property>
				<Property Name="Source[1].properties[0].value" Type="Bool">false</Property>
				<Property Name="Source[1].properties[1].type" Type="Str">Show Abort button</Property>
				<Property Name="Source[1].properties[1].value" Type="Bool">false</Property>
				<Property Name="Source[1].properties[2].type" Type="Str">Show toolbar</Property>
				<Property Name="Source[1].properties[2].value" Type="Bool">false</Property>
				<Property Name="Source[1].properties[3].type" Type="Str">Allow debugging</Property>
				<Property Name="Source[1].properties[3].value" Type="Bool">false</Property>
				<Property Name="Source[1].propertiesCount" Type="Int">4</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/support package/ygDLL.dll</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/S-TI-S JJ Simulation.vi</Property>
				<Property Name="Source[3].properties[0].type" Type="Str">Show toolbar</Property>
				<Property Name="Source[3].properties[0].value" Type="Bool">false</Property>
				<Property Name="Source[3].properties[1].type" Type="Str">Show Abort button</Property>
				<Property Name="Source[3].properties[1].value" Type="Bool">false</Property>
				<Property Name="Source[3].propertiesCount" Type="Int">2</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[3].type" Type="Str">VI</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/subVI/gen j disorder.vi</Property>
				<Property Name="Source[4].properties[0].type" Type="Str">Show Abort button</Property>
				<Property Name="Source[4].properties[0].value" Type="Bool">false</Property>
				<Property Name="Source[4].propertiesCount" Type="Int">1</Property>
				<Property Name="Source[4].type" Type="Str">VI</Property>
				<Property Name="Source[5].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[5].itemID" Type="Ref">/My Computer/support package/S-TI-S_JJ_Simulation Help.chm</Property>
				<Property Name="Source[5].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[6].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[6].itemID" Type="Ref">/My Computer/support package/Readme.rtf</Property>
				<Property Name="Source[6].sourceInclusion" Type="Str">Include</Property>
				<Property Name="SourceCount" Type="Int">7</Property>
				<Property Name="TgtF_companyName" Type="Str">UIUC DVH Group</Property>
				<Property Name="TgtF_fileDescription" Type="Str">This program is developed for calculation S-TI-S JJ Simulation of Josephson juncion with iregular current phase relation due to the Majarana Bound States.</Property>
				<Property Name="TgtF_internalName" Type="Str">S-TI-S JJ Simulation</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright ?2020 </Property>
				<Property Name="TgtF_productName" Type="Str">Diffraction pattern</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{E3301AAD-6402-4D4E-85C3-3D41CD82ED7D}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">S-TI-S JJ Simulation.exe</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
			<Item Name="JJ simulation" Type="Installer">
				<Property Name="Destination[0].name" Type="Str">JJ Simulation GUI</Property>
				<Property Name="Destination[0].parent" Type="Str">{3912416A-D2E5-411B-AFEE-B63654D690C0}</Property>
				<Property Name="Destination[0].tag" Type="Str">{92F98A4B-1FA3-4D2B-95DE-27C726434C27}</Property>
				<Property Name="Destination[0].type" Type="Str">userFolder</Property>
				<Property Name="DestinationCount" Type="Int">1</Property>
				<Property Name="INST_author" Type="Str">UIUC</Property>
				<Property Name="INST_autoIncrement" Type="Bool">true</Property>
				<Property Name="INST_buildLocation" Type="Path">../builds/JJ simulation GUI/JJ simulation</Property>
				<Property Name="INST_buildLocation.type" Type="Str">relativeToCommon</Property>
				<Property Name="INST_buildSpecName" Type="Str">JJ simulation</Property>
				<Property Name="INST_defaultDir" Type="Str">{92F98A4B-1FA3-4D2B-95DE-27C726434C27}</Property>
				<Property Name="INST_installerName" Type="Str">install.exe</Property>
				<Property Name="INST_productName" Type="Str">JJ simulation GUI</Property>
				<Property Name="INST_productVersion" Type="Str">1.0.27</Property>
				<Property Name="INST_readmeID" Type="Ref">/My Computer/support package/Readme.rtf</Property>
				<Property Name="InstSpecBitness" Type="Str">64-bit</Property>
				<Property Name="InstSpecVersion" Type="Str">23108276</Property>
				<Property Name="MSI_arpCompany" Type="Str">UIUC DVH group</Property>
				<Property Name="MSI_arpURL" Type="Str">publish.illinois.edu/dvhresearch/</Property>
				<Property Name="MSI_distID" Type="Str">{A3BB5762-0500-4232-A7ED-7C823A26E364}</Property>
				<Property Name="MSI_hideNonRuntimes" Type="Bool">true</Property>
				<Property Name="MSI_osCheck" Type="Int">0</Property>
				<Property Name="MSI_upgradeCode" Type="Str">{FA70ECAB-C47E-4DDF-9261-00AB81387624}</Property>
				<Property Name="MSI_windowMessage" Type="Str">The S-TI-S JJ Simulation program is going to be installed to your computer. </Property>
				<Property Name="MSI_windowTitle" Type="Str">S-TI-S JJ Simulation program installer</Property>
				<Property Name="RegDest[0].dirName" Type="Str">Software</Property>
				<Property Name="RegDest[0].dirTag" Type="Str">{DDFAFC8B-E728-4AC8-96DE-B920EBB97A86}</Property>
				<Property Name="RegDest[0].parentTag" Type="Str">2</Property>
				<Property Name="RegDestCount" Type="Int">1</Property>
				<Property Name="Source[0].dest" Type="Str">{92F98A4B-1FA3-4D2B-95DE-27C726434C27}</Property>
				<Property Name="Source[0].File[0].dest" Type="Str">{92F98A4B-1FA3-4D2B-95DE-27C726434C27}</Property>
				<Property Name="Source[0].File[0].name" Type="Str">S-TI-S JJ Simulation.exe</Property>
				<Property Name="Source[0].File[0].Shortcut[0].destIndex" Type="Int">0</Property>
				<Property Name="Source[0].File[0].Shortcut[0].name" Type="Str">S-TI-S JJ Simulation</Property>
				<Property Name="Source[0].File[0].Shortcut[0].subDir" Type="Str">JJ simulation GUI</Property>
				<Property Name="Source[0].File[0].Shortcut[1].destIndex" Type="Int">1</Property>
				<Property Name="Source[0].File[0].Shortcut[1].name" Type="Str">S-TI-S JJ Simulation</Property>
				<Property Name="Source[0].File[0].Shortcut[1].subDir" Type="Str"></Property>
				<Property Name="Source[0].File[0].ShortcutCount" Type="Int">2</Property>
				<Property Name="Source[0].File[0].tag" Type="Str">{E3301AAD-6402-4D4E-85C3-3D41CD82ED7D}</Property>
				<Property Name="Source[0].File[1].dest" Type="Str">{92F98A4B-1FA3-4D2B-95DE-27C726434C27}</Property>
				<Property Name="Source[0].File[1].name" Type="Str">Readme.rtf</Property>
				<Property Name="Source[0].File[1].Shortcut[0].destIndex" Type="Int">0</Property>
				<Property Name="Source[0].File[1].Shortcut[0].name" Type="Str">Readme</Property>
				<Property Name="Source[0].File[1].Shortcut[0].subDir" Type="Str">JJ simulation GUI</Property>
				<Property Name="Source[0].File[1].ShortcutCount" Type="Int">1</Property>
				<Property Name="Source[0].File[1].tag" Type="Ref">/My Computer/support package/Readme.rtf</Property>
				<Property Name="Source[0].FileCount" Type="Int">2</Property>
				<Property Name="Source[0].name" Type="Str">S-TI-S JJ Simulation</Property>
				<Property Name="Source[0].tag" Type="Ref">/My Computer/Build Specifications/S-TI-S JJ Simulation</Property>
				<Property Name="Source[0].type" Type="Str">EXE</Property>
				<Property Name="SourceCount" Type="Int">1</Property>
			</Item>
			<Item Name="Ic distribution simulation" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{7DA268A8-FB5E-4D9D-933D-463B54831D8B}</Property>
				<Property Name="App_INI_GUID" Type="Str">{44A31273-4F32-48B5-9710-8E88A7A33A64}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_serverType" Type="Int">0</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{69713F66-9D70-4EF4-BEE8-12BABEB782A9}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Ic distribution simulation</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/Ic distribution simulation</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{D14B89AF-9E02-4CC9-ADFE-B74866757499}</Property>
				<Property Name="Bld_version.build" Type="Int">22</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Ic distribution simulation.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/Ic distribution simulation/Ic distribution simulation.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/Ic distribution simulation/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{53C87C55-83E2-4D78-A373-86D564471384}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Ic distribution simulation.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/dll/ygDLL.dll</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="SourceCount" Type="Int">3</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Ic distribution simulation</Property>
				<Property Name="TgtF_internalName" Type="Str">Ic distribution simulation</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2021 </Property>
				<Property Name="TgtF_productName" Type="Str">Ic distribution simulation</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{048529EA-7060-46CE-9032-D5A458BE0625}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Ic distribution simulation.exe</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
