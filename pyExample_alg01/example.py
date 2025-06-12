import sys
import os
cur_dir = os.path.dirname(__file__)
pyd_dir = os.path.join(cur_dir, 'build/Release')
sys.path.append(os.path.abspath(pyd_dir))

# NOTE: You will likely see an error here for whatever IDE you use.
# If so it is likely because the steps given in the README_py.md have not been
# followed or the IDE does not recognize that the .pyd file is inside of
# a path that was joined in the above lines.
import rounder
import argparse

def main():
    r = rounder.Rounder()
    parser = argparse.ArgumentParser()
    parser.add_argument("-i",
                        "--input",
                        action = "store",
                        type = float,
                        help = "The number that gets rounded")
    args = parser.parse_args()
    num = args.input if args.input else 5.5

    print(r.round(num))

if __name__ == "__main__":
    main()
