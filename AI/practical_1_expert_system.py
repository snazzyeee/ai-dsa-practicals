# Title: Building an Expert System Using Rule-Based Systems
#
# Problem statement:
# Develop a rule-based expert system that provides simple decision-making using IF-THEN rules and
# forward or backward chaining.

# Each rule contains the symptoms needed and the result to show.
# These are only example rules for the practical.
RULES = [
    ({"fever", "cough"}, "flu"),
    ({"sneezing", "runny nose"}, "cold"),
    ({"headache", "nausea"}, "migraine"),
]

def diagnose(symptoms, rules):
    """Return the conclusions whose required symptoms are all present."""
    matches = []  # Start with no matching conclusions.
    for required, conclusion in rules:  # Check one IF-THEN rule at a time.
        if required.issubset(symptoms):  # Check whether all required symptoms exist.
            matches.append(conclusion)  # Save this rule's conclusion.
    return matches  # Give all matching conclusions back.


def main():
    print("Rule-based expert system")  # Show the program heading.
    entered = input("Enter symptoms separated by commas: ")  # Read user input.
    symptoms = set()  # A set stores each symptom only once.
    for item in entered.split(","):  # Separate the entered symptoms.
        item = item.strip().lower()  # Remove spaces and ignore letter case.
        if item:  # Ignore empty text between commas.
            symptoms.add(item)  # Store the valid symptom.

    if not symptoms:
        print("No symptoms entered.")
        return

    results = diagnose(symptoms, RULES)  # Apply every rule to the symptoms.

    if results:
        for result in results:
            print("Matched rule:", result)
    else:
        print("No matching rule found.")


if __name__ == "__main__":  # Run main only when this file is run directly.
    main()
