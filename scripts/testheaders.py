import sys

if __name__ == "__main__":
	with open(sys.argv[2], "r") as f:
		c = f.read()

	match sys.argv[1]:
		case '0':
			if "#include" in c:
				exit(1)
			else:
				exit(0)
		case '1':
			if "#include" in c and "#include <unistd.h>" not in c or c.count("#include") > 1:
				exit(1)
			else:
				exit(0)
		case _:
			print("Invalid argument!")
			exit(1)
