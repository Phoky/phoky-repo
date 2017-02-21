import subprocess
import sys

pid_list = subprocess.check_output(['ps | grep "a\.out"'], shell=True).split(' ')
pid_list.remove('')
pid = pid_list[0]
subprocess.call(["export MallocStackLogging=1"], shell=True)
print(subprocess.check_output(["leaks %s ; exit 0" % pid], shell=True, stderr=subprocess.STDOUT))
subprocess.call(["unset MallocStackLogging"], shell=True)
