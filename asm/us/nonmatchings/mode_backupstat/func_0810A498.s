.syntax unified
	.align 2, 0
	.global func_0810A498
	.thumb
	.thumb_func
	.type func_0810A498, %function
func_0810A498: @ 0810A498
	push {lr}
	adds r1, r0, #0x0
	adds r0, #0x38
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0810A4B6
	movs r2, #0x3A
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x05
	ldr r1, _0810A4BC @ =0x09D69374
	adds r0, r0, r1
	ldr r1, _0810A4C0 @ =0x05000080
	movs r2, #0x20
	bl func_08005BE8
_0810A4B6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810A4BC: .4byte 0x09D69374
_0810A4C0: .4byte 0x05000080
.syntax divided
