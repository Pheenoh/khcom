.syntax unified
	.align 2, 0
	.global task_ms_shop_hosi_2
	.thumb
	.thumb_func
	.type task_ms_shop_hosi_2, %function
task_ms_shop_hosi_2: @ 081095CC
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldrh r1, [r4, #0x12]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08109606
	ldr r0, [r4, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x04]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, _08109610 @ =0x09EF9A4C
	movs r5, #0x10
	ldsh r2, [r4, r5]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r4, #0x1C]
	ldr r4, [r4, #0x18]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl func_080023E0
_08109606:
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08109610: .4byte 0x09EF9A4C
.syntax divided
