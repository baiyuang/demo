#ifndef __LOCKER_H__
#define __LOCKER_H__

struct _locker;
typedef struct _locker locker_t;

typedef int (*create_fn)(locker_t *thiz);
typedef void (*destroy_fn)(locker_t *thiz);
typedef int (*lock_fn)(locker_t *thiz);
typedef int (*unlock_fn)(locker_t *thiz);

struct _locker
{
	create_fn create;
	destroy_fn destroy;
	lock_fn	lock;
	unlock_fn unlock;
	char priv[0];
};

static inline int locker_create(locker_t *thiz)
{
	if (thiz == NULL)
		return ERR;
	return thiz->create ? thiz->create(thiz) : ERR;
}

static inline void locker_destroy(locker_t *thiz)
{
	if (thiz == NULL)
		return;
	if (thiz->destroy)
		thiz->destroy(thiz);
}

static inline int locker_lock(locker_t *thiz)
{
	if (thiz == NULL)
		return ERR;
	return thiz->lock ? thiz->lock(thiz) : ERR;
}

static inline int locker_unlock(locker_t *thiz)
{
	if (thiz == NULL)
		return ERR;
	return thiz->unlock ? thiz->unlock(thiz) : ERR;
}
#endif