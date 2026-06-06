import os
import re

BASE_DIR = "."

# -------------------------------
# 1. Direct folder-based counts
# -------------------------------
FOLDER_MAP = {
    "Array": "Array",
    "LinkList": "LinkList",
    "Stack": "Stack",
    "Queue": "Queue",
    "Strings": "Strings",
    "Tree": "Tree",
    "Practice": "Practice",
    "Matrix": "Practice",  # matrix files are inside Practice in your repo
    "Concurrency / OS Concepts": "Practice",
    "Math / Number Programs": "Practice",
    "Maximum Subarray Sum": "Practice"
}

# -------------------------------
# 2. Count valid source files
# -------------------------------
def count_files(folder):
    path = os.path.join(BASE_DIR, folder)
    if not os.path.exists(path):
        return 0

    count = 0
    for root, _, files in os.walk(path):
        for f in files:
            if f.endswith(".c") or f.endswith(".cpp"):
                count += 1
    return count


# -------------------------------
# 3. Compute category counts
# -------------------------------
def get_counts():
    counts = {}

    for category, folder in FOLDER_MAP.items():
        counts[category] = count_files(folder)

    # Fix Matrix separately (only real matrix files)
    counts["Matrix"] = len([
        f for f in os.listdir("Practice")
        if f.endswith(".cpp") and "matrix" in f or "array_sum" in f
    ])

    # Fix Math separately (exclude DS logic files)
    counts["Math / Number Programs"] = len([
        f for f in os.listdir("Practice")
        if f.endswith(".cpp") and (
            "fact" in f or "prime" in f or "power" in f or
            "fibo" in f or "amstrong" in f or "perfect" in f
        )
    ])

    # Fix concurrency
    counts["Concurrency / OS Concepts"] = len([
        f for f in os.listdir("Practice")
        if f.endswith(".c") and (
            "thread" in f or "mutex" in f or "semaphore" in f or "race" in f
        )
    ])

    # Fix subarray section
    counts["Maximum Subarray Sum"] = len([
        f for f in os.listdir("Practice")
        if "sumarray" in f
    ])

    return counts


# -------------------------------
# 4. Generate markdown table
# -------------------------------
def generate_table(counts):
    total = sum(counts.values())

    lines = []
    lines.append("| Section | Count |")
    lines.append("|----------|------:|")

    for k, v in counts.items():
        lines.append(f"| {k} | {v} |")

    lines.append(f"| **Total** | **{total}** |")

    return "\n".join(lines)


# -------------------------------
# 5. Update README
# -------------------------------
def update_readme(table):
    with open("README.md", "r", encoding="utf-8") as f:
        content = f.read()

    pattern = r"<!-- STATS_START -->.*<!-- STATS_END -->"

    new_block = f"<!-- STATS_START -->\n{table}\n<!-- STATS_END -->"

    updated = re.sub(pattern, new_block, content, flags=re.DOTALL)

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(updated)


# -------------------------------
# Main
# -------------------------------
if __name__ == "__main__":
    counts = get_counts()
    table = generate_table(counts)
    update_readme(table)

    print("README stats updated successfully!")
