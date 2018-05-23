#include "notifier.h"
#include "chain.h"

static NOTIFIER_HEAD(event_chain);

int event_chain_register(struct notifier_block *n)
{
    return notifier_chain_register(&event_chain, n);
}

int event_chain_unregister(struct notifier_block *n)
{
    return notifier_chain_unregister(&event_chain, n);
}

int event_chain_notify(unsigned long val, void *v)
{
    return notifier_call_chain(&event_chain, val, v);
}