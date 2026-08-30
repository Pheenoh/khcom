.syntax unified
	.align 2, 0
	.global func_08031F60
	.thumb
	.thumb_func
	.type func_08031F60, %function
func_08031F60: @ 08031F60
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrb r5, [r4, #0x14]
	bl func_08031BC4
	ldrb r0, [r4, #0x14]
	cmp r5, r0
	beq _08031F90
	ldrb r1, [r4, #0x14]
	adds r0, r5, #0x0
	bl func_08005824
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _08031F82
	negs r0, r0
_08031F82:
	cmp r0, #0x64
	ble _08031F8A
	movs r0, #0x00
	b _08031F8E
_08031F8A:
	ldr r0, [r4, #0x10]
	asrs r0, r0, #0x01
_08031F8E:
	str r0, [r4, #0x10]
_08031F90:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
