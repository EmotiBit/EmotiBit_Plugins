import sys
import os
cur_dir = os.path.dirname(__file__)
pyd_dir = os.path.join(cur_dir, '../example_emotibitPacket/build/Release')
sys.path.append(os.path.abspath(pyd_dir))

# NOTE: You will likely see an error here for whatever IDE you use.
# If so it is likely because the steps given in the README_py.md have not been
# followed or the IDE does not recognize that the .pyd file is inside of
# a path that was joined in the above lines.
import EmotiBitPacket
import argparse

def main():
    parser = argparse.ArgumentParser()
    args = parser.parse_args()
    header = EmotiBitPacket.createHeader("TT",123456,8008,2,1,100)
    header_str = EmotiBitPacket.headerToString(header)
    print(header_str)
    # using createPacket function overload type 1
    # packet = EmotiBitPacket.createPacket("TT",8008,"MY_PAYLOAD",2,1,100)
    # print(packet, end='')
    # packet = EmotiBitPacket.createPacket("TT",8008,"MY_PAYLOAD",2,1,100)
    # print(packet, end='')
    # payload = ["1001","1002","1003","1004","1005"]
    # using createPacket function overload type 2
    payload = ["apple", "banana", "cherry", "date"]
    packet = EmotiBitPacket.createPacket("TT",8008,payload,1,100)
    print(packet, end='')
if __name__ == "__main__":
    main()
