.syntax unified
	.align 2, 0
	.global task_bos_boogie_mapanime_1
	.thumb
	.thumb_func
	.type task_bos_boogie_mapanime_1, %function
task_bos_boogie_mapanime_1: @ 080DABB4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	movs r2, #0x00
	ldr r0, _080DABF0 @ =0x0203C560
	ldrh r4, [r0, #0x00]
	cmp r4, #0x02
	bhi _080DABE8
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x02
	adds r6, r0, r7
	adds r5, r0, #0x0
_080DABCC:
	adds r0, r7, #0x0
	adds r0, #0x08
	adds r0, r0, r5
	ldr r1, [r0, #0x00]
	adds r0, r6, #0x0
	bl func_080DDDEC
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r6, #0x0C
	adds r5, #0x0C
	adds r4, #0x01
	cmp r4, #0x02
	bls _080DABCC
_080DABE8:
	movs r0, #0x01
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080DABF0: .4byte 0x0203C560
.syntax divided
