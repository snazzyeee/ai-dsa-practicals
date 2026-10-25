# Title: Building an Expert System Using Rule-Based Systems
#
# Problem statement:
# Develop a rule-based expert system that provides simple decision-making using IF-THEN rules and
# forward or backward chaining.

PRACTICE_MODE = True  # change to False to use the full-program area at the bottom

# Each rule contains the symptoms needed and the result to show.
# These are only example rules for the practical.
RULES = [
    ({"fever", "cough"}, "flu"),
    ({"sneezing", "runny nose"}, "cold"),
    ({"headache", "nausea"}, "migraine"),
]

# PSEUDOCODE: write your steps here.
#
#
#
#
#

# PRACTICE: check which rules match the user's symptoms.
# Return a list of matching results, or an empty list if none match.
def diagnose(symptoms, rules):
    raise NotImplementedError("TODO: write your rule-matching logic")


def main():
    print("Rule-based expert system practice")
    entered = input("Enter symptoms separated by commas: ")
    symptoms = {item.strip().lower() for item in entered.split(",") if item.strip()}

    if not symptoms:
        print("No symptoms entered.")
        return

    try:
        results = diagnose(symptoms, RULES)
    except NotImplementedError as error:
        print(error)
        return

    if results:
        for result in results:
            print("Matched rule:", result)
    else:
        print("No matching rule found.")


if __name__ == "__main__" and PRACTICE_MODE:
    main()

# FULL PROGRAM: set PRACTICE_MODE = False and write your whole program below.
