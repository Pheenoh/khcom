.syntax unified
	.align 2, 0
	.global func_08007874
	.thumb
	.thumb_func
	.type func_08007874, %function
func_08007874: @ 08007874
	ldr r1, _0800789C @ =0x04000134
	movs r0, #0x00
	strh r0, [r1, #0x00]
	subs r1, #0x0C
	strh r0, [r1, #0x00]
	ldr r2, _080078A0 @ =0x0400012A
	strh r0, [r2, #0x00]
	subs r1, #0x08
	strh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	strh r0, [r1, #0x00]
	adds r1, #0x02
	strh r0, [r1, #0x00]
	adds r1, #0x02
	strh r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_0800789C: .4byte 0x04000134
_080078A0: .4byte 0x0400012A
.syntax divided
