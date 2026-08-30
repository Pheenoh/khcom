.syntax unified
	.align 2, 0
	.global func_081192B0
	.thumb
	.thumb_func
	.type func_081192B0, %function
func_081192B0: @ 081192B0
	push {r7, lr}
	add sp, #-0x008
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x40]
	cmp r1, #0x01
	bne _081192D2
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x1C]
	ldr r0, [r1, #0x00]
	lsrs r1, r0, #0x01
	adds r0, r1, #0x0
	b _081192DE
	.byte 0x05, 0xE0
_081192D2:
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x1C]
	ldr r0, [r1, #0x00]
	lsrs r1, r0, #0x02
	adds r0, r1, #0x0
	b _081192DE
_081192DE:
	add sp, #0x008
	pop {r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
