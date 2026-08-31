.syntax unified
	.align 2, 0
	.global func_0808CDE8
	.thumb
	.thumb_func
	.type func_0808CDE8, %function
func_0808CDE8: @ 0808CDE8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0x0
	cmp r1, #0x01
	beq _0808CEE4
	cmp r1, #0x01
	bgt _0808CE00
	cmp r1, #0x00
	beq _0808CE08
	b _0808D054
_0808CE00:
	cmp r0, #0x02
	bne _0808CE06
	b _0808CFC0
_0808CE06:
	b _0808D054
_0808CE08:
	ldr r1, _0808CE9C @ =0x05000100
	ldr r0, _0808CEA0 @ =0x096142F8
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808CEA4 @ =0x05000120
	ldr r4, _0808CEA8 @ =0x09614238
	adds r0, r4, #0x0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808CEAC @ =0x05000140
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808CEB0 @ =0x09519C38
	movs r4, #0xC0
	lsls r4, r4, #0x01
	movs r0, #0x00
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808CEB4 @ =0x0951A2B8
	movs r0, #0x01
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808CEB8 @ =0x0951AAB8
	movs r0, #0x02
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808CEBC @ =0x0000FFB4
	ldr r2, _0808CEC0 @ =0x0000FFF2
	movs r0, #0x00
	bl SetBgScroll
	ldr r4, _0808CEC4 @ =0x0000FFA8
	ldr r2, _0808CEC8 @ =0x0000FFC0
	movs r0, #0x01
	adds r1, r4, #0x0
	bl SetBgScroll
	ldr r2, _0808CECC @ =0x0000FF90
	movs r0, #0x02
	adds r1, r4, #0x0
	bl SetBgScroll
	ldr r0, _0808CED0 @ =0x00000888
	adds r1, r5, r0
	movs r0, #0x64
	strh r0, [r1, #0x00]
	ldr r0, _0808CED4 @ =0x0000088E
	adds r1, r5, r0
	movs r0, #0x19
	strh r0, [r1, #0x00]
	ldr r1, _0808CED8 @ =0x0000088A
	adds r0, r5, r1
	movs r2, #0x66
	strh r2, [r0, #0x00]
	movs r0, #0x89
	lsls r0, r0, #0x04
	adds r1, r5, r0
	movs r0, #0x4B
	strh r0, [r1, #0x00]
	ldr r1, _0808CEDC @ =0x0000088C
	adds r0, r5, r1
	strh r2, [r0, #0x00]
	ldr r0, _0808CEE0 @ =0x00000892
	adds r1, r5, r0
	movs r0, #0x7A
	b _0808D052
_0808CE9C: .4byte 0x05000100
_0808CEA0: .4byte 0x096142F8
_0808CEA4: .4byte 0x05000120
_0808CEA8: .4byte 0x09614238
_0808CEAC: .4byte 0x05000140
_0808CEB0: .4byte 0x09519C38
_0808CEB4: .4byte 0x0951A2B8
_0808CEB8: .4byte 0x0951AAB8
_0808CEBC: .4byte 0x0000FFB4
_0808CEC0: .4byte 0x0000FFF2
_0808CEC4: .4byte 0x0000FFA8
_0808CEC8: .4byte 0x0000FFC0
_0808CECC: .4byte 0x0000FF90
_0808CED0: .4byte 0x00000888
_0808CED4: .4byte 0x0000088E
_0808CED8: .4byte 0x0000088A
_0808CEDC: .4byte 0x0000088C
_0808CEE0: .4byte 0x00000892
_0808CEE4:
	ldr r1, _0808CF78 @ =0x05000120
	ldr r0, _0808CF7C @ =0x096142F8
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808CF80 @ =0x05000100
	ldr r4, _0808CF84 @ =0x09614218
	adds r0, r4, #0x0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808CF88 @ =0x05000140
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808CF8C @ =0x09519AB8
	movs r4, #0xC0
	lsls r4, r4, #0x01
	movs r0, #0x00
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808CF90 @ =0x0951A438
	movs r0, #0x01
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808CF94 @ =0x0951AAB8
	movs r0, #0x02
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r4, _0808CF98 @ =0x0000FFA8
	ldr r2, _0808CF9C @ =0x0000FFF0
	movs r0, #0x00
	adds r1, r4, #0x0
	bl SetBgScroll
	ldr r1, _0808CFA0 @ =0x0000FFB4
	ldr r2, _0808CFA4 @ =0x0000FFC2
	movs r0, #0x01
	bl SetBgScroll
	ldr r2, _0808CFA8 @ =0x0000FF90
	movs r0, #0x02
	adds r1, r4, #0x0
	bl SetBgScroll
	ldr r1, _0808CFAC @ =0x00000888
	adds r0, r5, r1
	movs r2, #0x66
	strh r2, [r0, #0x00]
	ldr r0, _0808CFB0 @ =0x0000088E
	adds r1, r5, r0
	movs r0, #0x1B
	strh r0, [r1, #0x00]
	ldr r0, _0808CFB4 @ =0x0000088A
	adds r1, r5, r0
	movs r0, #0x64
	strh r0, [r1, #0x00]
	movs r0, #0x89
	lsls r0, r0, #0x04
	adds r1, r5, r0
	movs r0, #0x49
	strh r0, [r1, #0x00]
	ldr r1, _0808CFB8 @ =0x0000088C
	adds r0, r5, r1
	strh r2, [r0, #0x00]
	ldr r0, _0808CFBC @ =0x00000892
	adds r1, r5, r0
	movs r0, #0x7A
	b _0808D052
_0808CF78: .4byte 0x05000120
_0808CF7C: .4byte 0x096142F8
_0808CF80: .4byte 0x05000100
_0808CF84: .4byte 0x09614218
_0808CF88: .4byte 0x05000140
_0808CF8C: .4byte 0x09519AB8
_0808CF90: .4byte 0x0951A438
_0808CF94: .4byte 0x0951AAB8
_0808CF98: .4byte 0x0000FFA8
_0808CF9C: .4byte 0x0000FFF0
_0808CFA0: .4byte 0x0000FFB4
_0808CFA4: .4byte 0x0000FFC2
_0808CFA8: .4byte 0x0000FF90
_0808CFAC: .4byte 0x00000888
_0808CFB0: .4byte 0x0000088E
_0808CFB4: .4byte 0x0000088A
_0808CFB8: .4byte 0x0000088C
_0808CFBC: .4byte 0x00000892
_0808CFC0:
	ldr r1, _0808D05C @ =0x05000140
	ldr r0, _0808D060 @ =0x096142F8
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808D064 @ =0x05000100
	ldr r4, _0808D068 @ =0x09614218
	adds r0, r4, #0x0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808D06C @ =0x05000120
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0808D070 @ =0x09519AB8
	movs r4, #0xC0
	lsls r4, r4, #0x01
	movs r0, #0x00
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808D074 @ =0x0951A2B8
	movs r0, #0x01
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r1, _0808D078 @ =0x0951AC38
	movs r0, #0x02
	adds r2, r4, #0x0
	bl LoadBgMap
	ldr r4, _0808D07C @ =0x0000FFA8
	ldr r2, _0808D080 @ =0x0000FFF0
	movs r0, #0x00
	adds r1, r4, #0x0
	bl SetBgScroll
	ldr r2, _0808D084 @ =0x0000FFC0
	movs r0, #0x01
	adds r1, r4, #0x0
	bl SetBgScroll
	ldr r1, _0808D088 @ =0x0000FFB4
	ldr r2, _0808D08C @ =0x0000FF92
	movs r0, #0x02
	bl SetBgScroll
	ldr r1, _0808D090 @ =0x00000888
	adds r0, r5, r1
	movs r2, #0x66
	strh r2, [r0, #0x00]
	ldr r0, _0808D094 @ =0x0000088E
	adds r1, r5, r0
	movs r0, #0x1B
	strh r0, [r1, #0x00]
	ldr r1, _0808D098 @ =0x0000088A
	adds r0, r5, r1
	strh r2, [r0, #0x00]
	movs r0, #0x89
	lsls r0, r0, #0x04
	adds r1, r5, r0
	movs r0, #0x4B
	strh r0, [r1, #0x00]
	ldr r0, _0808D09C @ =0x0000088C
	adds r1, r5, r0
	movs r0, #0x64
	strh r0, [r1, #0x00]
	ldr r0, _0808D0A0 @ =0x00000892
	adds r1, r5, r0
	movs r0, #0x79
_0808D052:
	strh r0, [r1, #0x00]
_0808D054:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808D05C: .4byte 0x05000140
_0808D060: .4byte 0x096142F8
_0808D064: .4byte 0x05000100
_0808D068: .4byte 0x09614218
_0808D06C: .4byte 0x05000120
_0808D070: .4byte 0x09519AB8
_0808D074: .4byte 0x0951A2B8
_0808D078: .4byte 0x0951AC38
_0808D07C: .4byte 0x0000FFA8
_0808D080: .4byte 0x0000FFF0
_0808D084: .4byte 0x0000FFC0
_0808D088: .4byte 0x0000FFB4
_0808D08C: .4byte 0x0000FF92
_0808D090: .4byte 0x00000888
_0808D094: .4byte 0x0000088E
_0808D098: .4byte 0x0000088A
_0808D09C: .4byte 0x0000088C
_0808D0A0: .4byte 0x00000892
.syntax divided
