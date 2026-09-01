.syntax unified
	.align 2, 0
	.global TaskPoolInit
	.thumb
	.thumb_func
	.type TaskPoolInit, %function
TaskPoolInit: @ 08000E64
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	lsls r0, r4, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x02
	bl EwramAlloc
	str r0, [r6, #0x10]
	cmp r0, #0x00
	beq _08000E9C
	adds r0, r6, #0x0
	bl func_08000BA4
	cmp r4, #0x00
	ble _08000E9C
	movs r5, #0x00
_08000E86:
	ldr r2, [r6, #0x10]
	adds r2, r2, r5
	adds r0, r2, #0x0
	adds r0, #0x0C
	adds r1, r6, #0x0
	bl func_08000BB0
	adds r5, #0x24
	subs r4, #0x01
	cmp r4, #0x00
	bne _08000E86
_08000E9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
