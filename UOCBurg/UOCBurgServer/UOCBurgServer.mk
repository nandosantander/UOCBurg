##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCBurgServer
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg
ProjectPath            :=C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgServer
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
ObjectsFileList        :="UOCBurgServer.txt"
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
Objects0=$(IntermediateDirectory)/src_svrReportsMenu.c$(ObjectSuffix) $(IntermediateDirectory)/src_svrProductsMenu.c$(ObjectSuffix) $(IntermediateDirectory)/src_svrCategoriesMenu.c$(ObjectSuffix) $(IntermediateDirectory)/src_svrMain.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_svrReportsMenu.c$(ObjectSuffix): src/svrReportsMenu.c $(IntermediateDirectory)/src_svrReportsMenu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgServer/src/svrReportsMenu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_svrReportsMenu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_svrReportsMenu.c$(DependSuffix): src/svrReportsMenu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_svrReportsMenu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_svrReportsMenu.c$(DependSuffix) -MM src/svrReportsMenu.c

$(IntermediateDirectory)/src_svrReportsMenu.c$(PreprocessSuffix): src/svrReportsMenu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_svrReportsMenu.c$(PreprocessSuffix) src/svrReportsMenu.c

$(IntermediateDirectory)/src_svrProductsMenu.c$(ObjectSuffix): src/svrProductsMenu.c $(IntermediateDirectory)/src_svrProductsMenu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgServer/src/svrProductsMenu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_svrProductsMenu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_svrProductsMenu.c$(DependSuffix): src/svrProductsMenu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_svrProductsMenu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_svrProductsMenu.c$(DependSuffix) -MM src/svrProductsMenu.c

$(IntermediateDirectory)/src_svrProductsMenu.c$(PreprocessSuffix): src/svrProductsMenu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_svrProductsMenu.c$(PreprocessSuffix) src/svrProductsMenu.c

$(IntermediateDirectory)/src_svrCategoriesMenu.c$(ObjectSuffix): src/svrCategoriesMenu.c $(IntermediateDirectory)/src_svrCategoriesMenu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgServer/src/svrCategoriesMenu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_svrCategoriesMenu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_svrCategoriesMenu.c$(DependSuffix): src/svrCategoriesMenu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_svrCategoriesMenu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_svrCategoriesMenu.c$(DependSuffix) -MM src/svrCategoriesMenu.c

$(IntermediateDirectory)/src_svrCategoriesMenu.c$(PreprocessSuffix): src/svrCategoriesMenu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_svrCategoriesMenu.c$(PreprocessSuffix) src/svrCategoriesMenu.c

$(IntermediateDirectory)/src_svrMain.c$(ObjectSuffix): src/svrMain.c $(IntermediateDirectory)/src_svrMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgServer/src/svrMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_svrMain.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_svrMain.c$(DependSuffix): src/svrMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_svrMain.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_svrMain.c$(DependSuffix) -MM src/svrMain.c

$(IntermediateDirectory)/src_svrMain.c$(PreprocessSuffix): src/svrMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_svrMain.c$(PreprocessSuffix) src/svrMain.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgServer/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
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


