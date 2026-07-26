# Ghidra headless post-script: export decompiled C of the 68K sound driver.
import os
from ghidra.app.util.exporter import CppExporter
from ghidra.util.task import ConsoleTaskMonitor
from java.io import File

out = os.path.join(os.environ.get("SNATCHER_ROOT", "."), "analysis", "ghidra_out", "SDDRVS6_all.c")
exp = CppExporter()
ok = exp.export(File(out), currentProgram, None, ConsoleTaskMonitor())
print("export ok=%s -> %s" % (ok, out))
