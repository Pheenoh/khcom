.syntax unified
	.align 2, 0
	.global task_bos_dsd_rock_1
	.thumb
	.thumb_func
	.type task_bos_dsd_rock_1, %function
task_bos_dsd_rock_1: @ 080C45DC
	adds r2, r0, #0x0
	ldr r0, [r2, #0x00]
	movs r1, #0xD6
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _080C45FE
	ldr r0, [r2, #0x10]
	negs r0, r0
	str r0, [r2, #0x10]
	ldr r0, [r2, #0x18]
	negs r0, r0
	str r0, [r2, #0x18]
	b _080C460E
_080C45FE:
	ldr r0, [r2, #0x04]
	ldr r1, [r2, #0x10]
	adds r0, r0, r1
	str r0, [r2, #0x04]
	ldr r0, [r2, #0x0C]
	ldr r1, [r2, #0x18]
	adds r0, r0, r1
	str r0, [r2, #0x0C]
_080C460E:
	ldr r0, _080C462C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x08
	adds r0, r3, r1
	ldr r1, [r2, #0x04]
	cmp r1, r0
	bgt _080C4628
	ldr r2, _080C4630 @ =0xFFFF7800
	adds r0, r3, r2
	cmp r1, r0
	bge _080C4634
_080C4628:
	movs r0, #0x00
	b _080C4636
_080C462C: .4byte 0x02039B84
_080C4630: .4byte 0xFFFF7800
_080C4634:
	movs r0, #0x01
_080C4636:
	bx lr
.syntax divided
