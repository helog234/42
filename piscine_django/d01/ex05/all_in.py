#!/usr/bin/python3
import sys

def find_match(query_str):
    """
    Takes a single query string, finds if it's a state or capital,
    and prints the corresponding result.
    """
    states = {
        "Oregon": "OR",
        "Alabama": "AL",
        "New Jersey": "NJ",
        "Colorado": "CO"
    }
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
    }

    # remove whitespace from the start and end of the query string.
    cleaned_query = query_str.strip()

    if not cleaned_query:
        return

    # Prepare for case-insensitive comparison by creating a lowercase version.
    lower_query = cleaned_query.lower()

    # loop in items so i can apply .lower() to the keys/values
    for state, code in states.items():
        if lower_query == state.lower():
            print(f"{capital_cities[code]} is the capital of {state}")
            return

    # same for capital cities
    for state, code in states.items():
        capital = capital_cities[code]
        if lower_query == capital.lower():
            print(f"{capital} is the capital of {state}")
            return

    print(f"{cleaned_query} is neither a capital city nor a state")


def main():
    if len(sys.argv) != 2:
        return

    queries = sys.argv[1].split(',')

    for q in queries:
        find_match(q)


if __name__ == "__main__":
    main()