# Ghidra headless post-script: export whole program as decompiled C.
import os
from ghidra.app.util.exporter import CppExporter
from ghidra.util.task import ConsoleTaskMonitor
from java.io import File

out = os.path.join(os.environ.get("SNATCHER_ROOT", "."), "analysis", "ghidra_out", "MAIN_L_all.c")
exp = CppExporter()
try:
    # Ghidra 11.x: (decompiler timeout handled internally)
    exp.setOptions([])
except Exception:
    pass
ok = exp.export(File(out), currentProgram, None, ConsoleTaskMonitor())
print("export ok=%s -> %s" % (ok, out))
