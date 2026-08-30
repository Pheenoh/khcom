.syntax unified
	.align 2, 0
	.global func_08080228
	.thumb
	.thumb_func
	.type func_08080228, %function
func_08080228: @ 08080228
	ldr r1, _0808025C @ =0x02039B84
	ldr r0, [r1, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x30
	bne _08080258
	ldr r0, _08080260 @ =0x02034AAC
	ldr r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r3, #0xA5
	ldrb r2, [r3, #0x00]
	cmp r2, #0x00
	beq _0808024E
	ldr r0, _08080264 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xC2
	ldrb r0, [r0, #0x00]
	subs r0, r2, r0
	strb r0, [r3, #0x00]
_0808024E:
	ldr r1, [r1, #0x00]
	adds r1, #0xF8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_08080258:
	bx lr
	.byte 0x00, 0x00
_0808025C: .4byte 0x02039B84
_08080260: .4byte 0x02034AAC
_08080264: .4byte 0x02039DD4
.syntax divided
