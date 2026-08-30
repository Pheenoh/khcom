.syntax unified
	.align 2, 0
	.global func_0811095C
	.thumb
	.thumb_func
	.type func_0811095C, %function
func_0811095C: @ 0811095C
	push {r4, r5, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r5, [r0, #0x04]
	bl func_08110918
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _08110978
	cmp r4, #0x00
	bne _08110978
	strh r4, [r5, #0x10]
	movs r4, #0x01
_08110978:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
