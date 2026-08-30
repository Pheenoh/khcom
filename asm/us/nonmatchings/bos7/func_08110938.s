.syntax unified
	.align 2, 0
	.global func_08110938
	.thumb
	.thumb_func
	.type func_08110938, %function
func_08110938: @ 08110938
	push {r4, lr}
	ldr r4, [r0, #0x04]
	bl func_08110918
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x01
	bne _08110952
	movs r2, #0x12
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	bgt _08110952
	movs r1, #0x00
_08110952:
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
