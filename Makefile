TARGET = principal
CXX = g++

CXXFLAGS = -Wall -g -Iinclude


SRCDIR = src
OBJDIR = obj


SOURCES = $(wildcard $(SRCDIR)/*.cpp)

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)


$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)


$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


help:
	@echo "	===Comandos===			"
	@echo "	make run		- Ejecuta el programa"
	@echo "	make valgrind		- Ejecuta el programa usando valgrind"
	@echo "	make clean		- Elimina los .o y el ejecutable"
	@echo "	make help		- Muestra la lista de comandos"

	
clean:
	rm -rf $(OBJDIR) $(TARGET)


run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TARGET)