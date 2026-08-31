.syntax unified
	.align 2, 0
	.global task_monsgage_2
	.thumb
	.thumb_func
	.type task_monsgage_2, %function
task_monsgage_2: @ 0805CBE0
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, _0805CC30 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0805CC5A
	ldr r2, [r4, #0x14]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x03
	str r0, [sp, #0x00C]
	movs r0, #0xAC
	movs r1, #0x0C
	bl DrawSprite
	adds r0, r4, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0805CC5A
	ldr r0, [r4, #0x10]
	lsls r1, r0, #0x01
	cmp r1, #0x04
	ble _0805CC5A
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r1, r2
	ble _0805CC34
	movs r0, #0x00
	movs r3, #0x01
	b _0805CC38
_0805CC30: .4byte 0x02039B84
_0805CC34:
	movs r0, #0x00
	movs r3, #0x00
_0805CC38:
	bl AllocObjAffine
	adds r1, r0, #0x0
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x04]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x02
	str r0, [sp, #0x00C]
	movs r0, #0xAE
	movs r1, #0x10
	bl DrawSprite
_0805CC5A:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
