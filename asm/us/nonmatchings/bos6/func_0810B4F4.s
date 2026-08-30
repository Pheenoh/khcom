.syntax unified
	.align 2, 0
	.global func_0810B4F4
	.thumb
	.thumb_func
	.type func_0810B4F4, %function
func_0810B4F4: @ 0810B4F4
	push {lr}
	adds r1, r0, #0x0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0810B510
	movs r2, #0x02
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x05
	ldr r1, _0810B514 @ =0x09D69374
	adds r0, r0, r1
	ldr r1, _0810B518 @ =0x05000080
	movs r2, #0x20
	bl func_08005BE8
_0810B510:
	pop {r0}
	bx r0
_0810B514: .4byte 0x09D69374
_0810B518: .4byte 0x05000080
.syntax divided
