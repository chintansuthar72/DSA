.PHONY: clean All

All:
	@echo "----------Building project:[ DSA - Debug ]----------"
	@"$(MAKE)" -f  "DSA.mk"
clean:
	@echo "----------Cleaning project:[ DSA - Debug ]----------"
	@"$(MAKE)" -f  "DSA.mk" clean
