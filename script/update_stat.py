import os
import re

BASE_DIR = "."

CATEGORY_MAP = {
    "Array": "Array",
    "LinkList": "LinkList",
    "Stack": "Stack",
    "Queue": "Queue",
    "Strings": "Strings",
    "Tree": "Tree",
    "Practice": "Practice",
    "Matrix": "Matrix"
}

# Special grouping rules
SPECIAL_GROUPS = {
    "Practice (Arrays & Searching)": [
        "Practice"
    ],
    "Math / Number Programs": [
        "Practice"
    ],
    "Concurrency / OS Concepts": [
        "Practice"
    ],
    "Maximum Subarray Sum": [
        "Practice"
    ]
}

def count_files(folder):
    if not os.path.exists(folder):
        return 0

    count = 0
    for root, _, files in os.walk(folder):
        for f in files:
            if f.endswith(".c") or f.endswith(".cpp"):
                count += 1
    return count


def get_counts():
    counts = {}

    for cat in CATEGORY_MAP:
        counts[cat] = count_files(os.path.join(BASE_DIR, cat))

    # Override grouped categories manually (if needed)
    counts["LinkList"] = count_files("LinkList")
    counts["Tree"] = count_files("Tree")

    # You can adjust these if you want smarter grouping
    counts["Practice (Arrays & Searching)"] = len([
        f for f in os.listdir("Practice")
        if f.endswith(".cpp") and "array" in f or "search" in f
    ])

    return counts


def generate_table(counts):
    total = sum(counts.values())

    table = []
    table.append("| Section | Count |")
    table.append("|----------|------:|")

    for k, v in counts.items():
        table.append(f"| {k} | {v} |")

    table.append(f"| **Total** | **{total}** |")

    return "\n".join(table)


def update_readme(table):
    with open("README.md", "r", encoding="utf-8") as f:
        content = f.read()

    pattern = r"<!-- STATS_START -->.*<!-- STATS_END -->"

    new_block = f"<!-- STATS_START -->\n{table}\n<!-- STATS_END -->"

    updated = re.sub(pattern, new_block, content, flags=re.DOTALL)

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(updated)


if __name__ == "__main__":
    counts = get_counts()
    table = generate_table(counts)
    update_readme(table)

    print("README stats updated successfully!")
