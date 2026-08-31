.syntax unified
	.align 2, 0
	.global task_status_friend_3
	.thumb
	.thumb_func
	.type task_status_friend_3, %function
task_status_friend_3: @ 080D8B54
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
	ldrh r0, [r6, #0x24]
	cmp r5, r0
	bge _080D8B7E
	adds r7, r6, #0x0
_080D8B62:
	lsls r4, r5, #0x02
	ldm r7!, {r0}
	bl ReleaseObjTiles
	adds r0, r6, #0x0
	adds r0, #0x0C
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	adds r5, #0x01
	ldrh r0, [r6, #0x24]
	cmp r5, r0
	blt _080D8B62
_080D8B7E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
