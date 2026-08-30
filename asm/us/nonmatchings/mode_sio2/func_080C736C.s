.syntax unified
	.align 2, 0
	.global func_080C736C
	.thumb
	.thumb_func
	.type func_080C736C, %function
func_080C736C: @ 080C736C
	ldr r0, _080C738C @ =0x02034CFC
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _080C7390 @ =0x02034D00
	str r1, [r0, #0x00]
	ldr r0, _080C7394 @ =0x02034D04
	str r1, [r0, #0x00]
	ldr r0, _080C7398 @ =0x02034D08
	movs r2, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _080C739C @ =0x02034D0C
	str r1, [r0, #0x00]
	ldr r0, _080C73A0 @ =0x02034D10
	strb r2, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_080C738C: .4byte 0x02034CFC
_080C7390: .4byte 0x02034D00
_080C7394: .4byte 0x02034D04
_080C7398: .4byte 0x02034D08
_080C739C: .4byte 0x02034D0C
_080C73A0: .4byte 0x02034D10
.syntax divided
