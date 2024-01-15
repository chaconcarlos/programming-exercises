import random

def print_invitees(invitees_list):
    """Prints the list of invitees.

    Keyword arguments:
    invitees_list -- The list of invitees.
    """
    if (len(invitees_list) <= 0):
        print('\nNO ONE IS INVITED TO THE PARTY NOW.')
        return

    print('\nThe following people are invited to the party:')

    for invitee in invitees_list:
        print('  ' + invitee + ' is invited to the party!')

def get_declined_invitations(invitees_list):
    """Gets the invitees that declined the invitation.

    Keyword arguments:
    invitees_list -- The list of invitees.
    """
    missing_invitee_index = random.randrange(0, len(party_invitees) - 1)
    missing_invitee = party_invitees[missing_invitee_index]

    return missing_invitee_index, missing_invitee

def run_missing_invitee(invitees_list):
    """Runs the missing invitee exercise.

    Keyword arguments:
    invitees_list -- The list of invitees.
    """
    print('===========CHANGE GUEST LIST===========')
    print_invitees(invitees_list)

    missing_invitee_index, missing_invitee = get_declined_invitations(invitees_list)
    
    print('\n====!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!====')
    print('OH NO! ' + missing_invitee + ' can\'t come to the party!')
    print('========================================================')

    invitees_list[missing_invitee_index] = "Hakeem Olajuwon"

    print_invitees(invitees_list)

def run_more_guests(invitees_list):
    """Runs the more guests exercise.

    Keyword arguments:
    invitees_list -- The list of invitees.
    """
    print('===========MORE GUESTS===========')
    print_invitees(invitees_list)

    invitees_list.insert(0, 'John Travolta')
    invitees_list.insert(len(invitees_list) // 2, 'Fulanito')
    invitees_list.append('Madonna')

    print_invitees(invitees_list)

def run_shrinking_guest_list(invitees_list):
    """Runs the more guests exercise.

    Keyword arguments:
    invitees_list -- The list of invitees.
    """
    print('===========SHRINKING GUEST LIST===========')
    print_invitees(invitees_list)

    print('\n====!!!!!!!!!!!!!!!!!!!!!====')
    print('OH NO! WE HAVE NO ENOUGH SPACE!')
    print('===============================')

    while(len(invitees_list) > 2):
        uninvited_guest = invitees_list.pop()
        print('  ' + uninvited_guest + ' is not invited anymore. BYE BYE!')

    print_invitees(invitees_list)


def run(invitees_list):
    """Runs the party invitations program.

    Keyword arguments:
    invitees_list -- The list of invitees.
    """
    run_missing_invitee(invitees_list)
    run_more_guests(invitees_list)
    run_shrinking_guest_list(invitees_list)

    while(len(invitees_list) > 0):
        del invitees_list[0]

    print_invitees(party_invitees)


party_invitees = [
    "Michael Jordan",
    "Barry Bonds",
    "Wayne Wretzky"
]

run(party_invitees)







