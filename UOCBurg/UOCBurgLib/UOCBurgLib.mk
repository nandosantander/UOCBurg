##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCBurgLib
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg
ProjectPath            :=C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgLib
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
OutputFile             :=../lib/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCBurgLib.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

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
Objects0=$(IntermediateDirectory)/src_orders.c$(ObjectSuffix) $(IntermediateDirectory)/src_products.c$(ObjectSuffix) $(IntermediateDirectory)/src_operations.c$(ObjectSuffix) $(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/src_categories.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\NANDO\Downloads\UOCBurg_SolucionTotal\UOCBurg/.build-debug"
	@echo rebuilt > "C:\Users\NANDO\Downloads\UOCBurg_SolucionTotal\UOCBurg/.build-debug/UOCBurgLib"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_orders.c$(ObjectSuffix): src/orders.c $(IntermediateDirectory)/src_orders.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgLib/src/orders.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_orders.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_orders.c$(DependSuffix): src/orders.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_orders.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_orders.c$(DependSuffix) -MM src/orders.c

$(IntermediateDirectory)/src_orders.c$(PreprocessSuffix): src/orders.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_orders.c$(PreprocessSuffix) src/orders.c

$(IntermediateDirectory)/src_products.c$(ObjectSuffix): src/products.c $(IntermediateDirectory)/src_products.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgLib/src/products.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_products.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_products.c$(DependSuffix): src/products.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_products.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_products.c$(DependSuffix) -MM src/products.c

$(IntermediateDirectory)/src_products.c$(PreprocessSuffix): src/products.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_products.c$(PreprocessSuffix) src/products.c

$(IntermediateDirectory)/src_operations.c$(ObjectSuffix): src/operations.c $(IntermediateDirectory)/src_operations.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgLib/src/operations.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_operations.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_operations.c$(DependSuffix): src/operations.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_operations.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_operations.c$(DependSuffix) -MM src/operations.c

$(IntermediateDirectory)/src_operations.c$(PreprocessSuffix): src/operations.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_operations.c$(PreprocessSuffix) src/operations.c

$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix): src/helpers.c $(IntermediateDirectory)/src_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgLib/src/helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_helpers.c$(DependSuffix): src/helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_helpers.c$(DependSuffix) -MM src/helpers.c

$(IntermediateDirectory)/src_helpers.c$(PreprocessSuffix): src/helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_helpers.c$(PreprocessSuffix) src/helpers.c

$(IntermediateDirectory)/src_categories.c$(ObjectSuffix): src/categories.c $(IntermediateDirectory)/src_categories.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/NANDO/Downloads/UOCBurg_SolucionTotal/UOCBurg/UOCBurgLib/src/categories.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_categories.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_categories.c$(DependSuffix): src/categories.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_categories.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_categories.c$(DependSuffix) -MM src/categories.c

$(IntermediateDirectory)/src_categories.c$(PreprocessSuffix): src/categories.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_categories.c$(PreprocessSuffix) src/categories.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


