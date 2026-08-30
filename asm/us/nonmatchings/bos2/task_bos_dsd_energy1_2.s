.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy1_2
	.thumb
	.thumb_func
	.type task_bos_dsd_energy1_2, %function
task_bos_dsd_energy1_2: @ 080C4BA4
	push {r4, r5, r6, lr}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r0, #0x48
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080C4C42
	ldr r2, [r5, #0x0C]
	cmp r2, #0x00
	blt _080C4BD4
	ldr r0, _080C4BD0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _080C4BD4
	movs r6, #0x00
	b _080C4C00
	.byte 0x00, 0x00
_080C4BD0: .4byte 0x02039B84
_080C4BD4:
	negs r1, r2
	cmp r1, #0x00
	bge _080C4BDC
	adds r1, #0x7F
_080C4BDC:
	asrs r1, r1, #0x07
	movs r0, #0x80
	lsls r0, r0, #0x02
	subs r2, r0, r1
	cmp r2, #0x7F
	bgt _080C4BEA
	movs r2, #0x80
_080C4BEA:
	movs r3, #0x00
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	ble _080C4BF6
	movs r3, #0x01
_080C4BF6:
	movs r0, #0x00
	adds r1, r2, #0x0
	bl func_08002CB4
	adds r6, r0, #0x0
_080C4C00:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	movs r0, #0x00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r5, #0x44]
	ldr r4, [r5, #0x00]
	movs r5, #0xDD
	lsls r5, r5, #0x02
	adds r3, r4, r5
	ldr r3, [r3, #0x00]
	adds r5, #0x04
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _080C4C4C @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl func_080023E0
_080C4C42:
	add sp, #0x014
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C4C4C: .4byte 0x0000FFF0
.syntax divided
