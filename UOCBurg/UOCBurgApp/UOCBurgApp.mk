##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCBurgApp
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg
ProjectPath            :=C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgApp
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=NANDO
Date                   :=21/10/2018
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCBurgApp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../UOCBurgLib/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UOCBurgLib 
ArLibs                 :=  "UOCBurgLib" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall  -Werror $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall  -Werror $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/src_appOrder.c$(ObjectSuffix) $(IntermediateDirectory)/src_appMain.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d "..\.build-debug\UOCBurgLib" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

"..\.build-debug\UOCBurgLib":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\UOCBurgLib"




MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_appOrder.c$(ObjectSuffix): src/appOrder.c $(IntermediateDirectory)/src_appOrder.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgApp/src/appOrder.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_appOrder.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_appOrder.c$(DependSuffix): src/appOrder.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_appOrder.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_appOrder.c$(DependSuffix) -MM src/appOrder.c

$(IntermediateDirectory)/src_appOrder.c$(PreprocessSuffix): src/appOrder.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_appOrder.c$(PreprocessSuffix) src/appOrder.c

$(IntermediateDirectory)/src_appMain.c$(ObjectSuffix): src/appMain.c $(IntermediateDirectory)/src_appMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgApp/src/appMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_appMain.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_appMain.c$(DependSuffix): src/appMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_appMain.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_appMain.c$(DependSuffix) -MM src/appMain.c

$(IntermediateDirectory)/src_appMain.c$(PreprocessSuffix): src/appMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_appMain.c$(PreprocessSuffix) src/appMain.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgApp/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


