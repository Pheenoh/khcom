.syntax unified
	.align 2, 0
	.global func_080A3370
	.thumb
	.thumb_func
	.type func_080A3370, %function
func_080A3370: @ 080A3370
	push {r4, r5, lr}
	adds r3, r0, #0x0
	movs r2, #0x00
	ldr r5, _080A3390 @ =0x0000010D
	ldr r4, _080A3394 @ =0x0203A8C0
_080A337A:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
	adds r2, #0x01
	cmp r2, r5
	ble _080A337A
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080A3390: .4byte 0x0000010D
_080A3394: .4byte 0x0203A8C0
.syntax divided
