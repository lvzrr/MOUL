import sys
import os

if __name__ == "__main__":
	file_path = sys.argv[2]
	dir_path = os.path.dirname(file_path)
	files_in_dir = os.listdir(dir_path)

	if len(files_in_dir) > 1:
		exit(2)

	with open(file_path, "r") as f:
		c = f.read()
	f.close()

	path = file_path.split("/")

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
