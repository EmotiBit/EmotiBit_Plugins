import sys
import os
cur_dir = os.path.dirname(__file__)
pyd_dir = os.path.join(cur_dir, '../cppExample_alg01/build/Release')
sys.path.append(os.path.abspath(pyd_dir))
import rounder

r = rounder.Rounder()
if len(sys.argv) >= 1:
    num = sys.argv[1]
else:
    num = 5.5
print(r.round(num))
