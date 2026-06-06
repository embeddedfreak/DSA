import re

README_FILE = "README.md"

# Sections you want to track
SECTIONS = [
    "Array",
    "LinkList",
    "Stack",
    "Queue",
    "Strings",
    "Tree",
    "Practice",
    "Math",
    "Matrix",
    "Concurrency / OS Concepts"
]

def count_section(content, section):
    """
    Count table rows under a section until next # heading
    """
    pattern = rf"# {re.escape(section)}(.*?)(?:\n# |\Z)"
    match = re.search(pattern, content, re.DOTALL)

    if not match:
        return 0

    block = match.group(1)

    # Count rows starting with "|"
    rows = re.findall(r"^\| \d+\s*\|", block, re.MULTILINE)

    return len(rows)


def update_stats(content, counts):
    total = sum(counts.values())

    table = []
    table.append("<!-- STATS_START -->")
    table.append("| Section | Count |")
    table.append("|----------|------:|")

    for k, v in counts.items():
        lines.append(f"| {k} | {v} |")

    table.append(f"| **Total** | **{total}** |")
    table.append("<!-- STATS_END -->")

    new_block = "\n".join(table)

    return re.sub(
        r"<!-- STATS_START -->.*<!-- STATS_END -->",
        new_block,
        content,
        flags=re.DOTALL
    )


# -------------------------------
# Main
# -------------------------------
if __name__ == "__main__":
    with open(README_FILE, "r", encoding="utf-8") as f:
        content = f.read()

    counts = {}

    for section in SECTIONS:
        counts[section] = count_section(content, section)

    updated = update_stats(content, counts)

    with open(README_FILE, "w", encoding="utf-8") as f:
        f.write(updated)

    print("README stats updated from README itself successfully!")
