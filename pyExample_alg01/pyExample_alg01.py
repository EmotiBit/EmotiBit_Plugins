import sys
import os
cur_dir = os.path.dirname(__file__)
pyd_dir = os.path.join(cur_dir, '../cppExample_alg01/build/Release')
sys.path.append(os.path.abspath(pyd_dir))
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
