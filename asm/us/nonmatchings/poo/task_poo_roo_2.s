.syntax unified
	.align 2, 0
	.global task_poo_roo_2
	.thumb
	.thumb_func
	.type task_poo_roo_2, %function
task_poo_roo_2: @ 080CF064
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r0, [r6, #0x28]
	asrs r0, r0, #0x08
	ldr r1, _080CF0E0 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [r6, #0x2C]
	asrs r7, r0, #0x08
	ldr r0, [r6, #0x30]
	asrs r0, r0, #0x08
	adds r0, r7, r0
	ldr r1, _080CF0E4 @ =0x0203C3F8
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r6, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	movs r5, #0x80
	lsls r5, r5, #0x04
	cmp r0, #0x00
	beq _080CF09C
	adds r5, #0x01
_080CF09C:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	lsls r5, r7, #0x02
	ldr r7, _080CF0E8 @ =0xFFFFEFFA
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	adds r0, r6, #0x0
	adds r0, #0xB4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CF0D6
	adds r0, r6, #0x0
	adds r0, #0x98
	bl func_08000EE0
_080CF0D6:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CF0E0: .4byte 0x0203C40C
_080CF0E4: .4byte 0x0203C3F8
_080CF0E8: .4byte 0xFFFFEFFA
.syntax divided
