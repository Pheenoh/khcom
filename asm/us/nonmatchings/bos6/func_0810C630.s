.syntax unified
	.align 2, 0
	.global func_0810C630
	.thumb
	.thumb_func
	.type func_0810C630, %function
func_0810C630: @ 0810C630
	adds r1, r0, #0x0
	ldr r2, _0810C644 @ =0x0000FFFF
	movs r3, #0xFA
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0810C648
	movs r2, #0x00
	b _0810C656
_0810C644: .4byte 0x0000FFFF
_0810C648:
	movs r3, #0xCD
	lsls r3, r3, #0x02
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0810C656
	movs r2, #0x01
_0810C656:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	bx lr
.syntax divided
