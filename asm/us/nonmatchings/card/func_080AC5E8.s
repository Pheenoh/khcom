.syntax unified
	.align 2, 0
	.global func_080AC5E8
	.thumb
	.thumb_func
	.type func_080AC5E8, %function
func_080AC5E8: @ 080AC5E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	adds r7, r3, #0x0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	add r0, sp, #0x004
	movs r1, #0x00
	movs r2, #0x0C
	bl memset
	movs r0, #0x00
	mov r8, r0
	movs r2, #0x00
	cmp r8, r4
	bcs _080AC62C
_080AC610:
	lsls r0, r2, #0x02
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0x04
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x28]
	str r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r4
	bcc _080AC610
_080AC62C:
	ldr r0, _080AC680 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080AC68C
	ldr r0, _080AC684 @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AC68C
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r1, r0
	cmp r1, #0x00
	bne _080AC68C
	ldr r0, _080AC688 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xEE
	ldrb r0, [r2, #0x00]
	cmp r0, #0x01
	beq _080AC676
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r0, r0, r3
	mov r12, r0
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x1D
	ble _080AC68C
_080AC676:
	strb r1, [r2, #0x00]
	movs r0, #0x6C
	bl _080AD136
	lsls r0, r0, #0x00
_080AC680:
	ldr r3, [sp, #0x2C0]
	lsls r3, r0, #0x08
_080AC684:
	ldr r3, [sp, #0x210]
	lsls r3, r0, #0x08
_080AC688:
	ldr r5, [sp, #0x350]
	lsls r3, r0, #0x08
_080AC68C:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x0A
	ldr r1, [sp, #0x004]
	orrs r1, r0
	ldr r0, [sp, #0x00C]
	lsls r0, r0, #0x14
	orrs r1, r0
	lsls r0, r4, #0x1E
	orrs r1, r0
	ldr r0, _080AC6E8 @ =0xCC9324C9
	cmp r1, r0
	bne _080AC6A6
	b _080ACC34
_080AC6A6:
	cmp r1, r0
	bls _080AC6AC
	b _080AC908
_080AC6AC:
	ldr r0, _080AC6EC @ =0x800A7E9F
	cmp r1, r0
	bne _080AC6B4
	b _080ACBE4
_080AC6B4:
	cmp r1, r0
	bls _080AC6BA
	b _080AC7F8
_080AC6BA:
	ldr r0, _080AC6F0 @ =0x80043D0F
	cmp r1, r0
	bne _080AC6C2
	b _080ACBB8
_080AC6C2:
	cmp r1, r0
	bhi _080AC764
	ldr r0, _080AC6F4 @ =0x80034CD3
	cmp r1, r0
	bne _080AC6CE
	b _080ACBA0
_080AC6CE:
	cmp r1, r0
	bhi _080AC71C
	ldr r0, _080AC6F8 @ =0x8002D4B5
	cmp r1, r0
	bne _080AC6DA
	b _080ACB98
_080AC6DA:
	cmp r1, r0
	bhi _080AC700
	ldr r0, _080AC6FC @ =0x8002ACAB
	cmp r1, r0
	bne _080AC6E6
	b _080ACB90
_080AC6E6:
	b _080ACD64
_080AC6E8: .4byte 0xCC9324C9
_080AC6EC: .4byte 0x800A7E9F
_080AC6F0: .4byte 0x80043D0F
_080AC6F4: .4byte 0x80034CD3
_080AC6F8: .4byte 0x8002D4B5
_080AC6FC: .4byte 0x8002ACAB
_080AC700:
	ldr r0, _080AC714 @ =0x8002FCBF
	cmp r1, r0
	bne _080AC708
	b _080ACB94
_080AC708:
	ldr r0, _080AC718 @ =0x800324C9
	cmp r1, r0
	bne _080AC710
	b _080ACB9C
_080AC710:
	b _080ACD64
	.byte 0x00, 0x00
_080AC714: .4byte 0x8002FCBF
_080AC718: .4byte 0x800324C9
_080AC71C:
	ldr r0, _080AC73C @ =0x8003C4F1
	cmp r1, r0
	bne _080AC724
	b _080ACBB0
_080AC724:
	cmp r1, r0
	bhi _080AC748
	ldr r0, _080AC740 @ =0x800374DD
	cmp r1, r0
	bne _080AC730
	b _080ACBA4
_080AC730:
	ldr r0, _080AC744 @ =0x80039CE7
	cmp r1, r0
	bne _080AC738
	b _080ACBA8
_080AC738:
	b _080ACD64
	.byte 0x00, 0x00
_080AC73C: .4byte 0x8003C4F1
_080AC740: .4byte 0x800374DD
_080AC744: .4byte 0x80039CE7
_080AC748:
	ldr r0, _080AC75C @ =0x8003ECFB
	cmp r1, r0
	bne _080AC750
	b _080ACBAC
_080AC750:
	ldr r0, _080AC760 @ =0x80041505
	cmp r1, r0
	bne _080AC758
	b _080ACBB4
_080AC758:
	b _080ACD64
	.byte 0x00, 0x00
_080AC75C: .4byte 0x8003ECFB
_080AC760: .4byte 0x80041505
_080AC764:
	ldr r0, _080AC788 @ =0x80050541
	cmp r1, r0
	bne _080AC76C
	b _080ACBCC
_080AC76C:
	cmp r1, r0
	bhi _080AC7B0
	ldr r0, _080AC78C @ =0x80048D23
	cmp r1, r0
	bne _080AC778
	b _080ACBC0
_080AC778:
	cmp r1, r0
	bhi _080AC794
	ldr r0, _080AC790 @ =0x80046519
	cmp r1, r0
	bne _080AC784
	b _080ACBBC
_080AC784:
	b _080ACD64
	.byte 0x00, 0x00
_080AC788: .4byte 0x80050541
_080AC78C: .4byte 0x80048D23
_080AC790: .4byte 0x80046519
_080AC794:
	ldr r0, _080AC7A8 @ =0x8004B52D
	cmp r1, r0
	bne _080AC79C
	b _080ACBC4
_080AC79C:
	ldr r0, _080AC7AC @ =0x8004DD37
	cmp r1, r0
	bne _080AC7A4
	b _080ACBC8
_080AC7A4:
	b _080ACD64
	.byte 0x00, 0x00
_080AC7A8: .4byte 0x8004B52D
_080AC7AC: .4byte 0x8004DD37
_080AC7B0:
	ldr r0, _080AC7D0 @ =0x80057D5F
	cmp r1, r0
	bne _080AC7B8
	b _080ACBD8
_080AC7B8:
	cmp r1, r0
	bhi _080AC7DC
	ldr r0, _080AC7D4 @ =0x80052D4B
	cmp r1, r0
	bne _080AC7C4
	b _080ACBD0
_080AC7C4:
	ldr r0, _080AC7D8 @ =0x80055555
	cmp r1, r0
	bne _080AC7CC
	b _080ACBD4
_080AC7CC:
	b _080ACD64
	.byte 0x00, 0x00
_080AC7D0: .4byte 0x80057D5F
_080AC7D4: .4byte 0x80052D4B
_080AC7D8: .4byte 0x80055555
_080AC7DC:
	ldr r0, _080AC7F0 @ =0x8005A569
	cmp r1, r0
	bne _080AC7E4
	b _080ACBDC
_080AC7E4:
	ldr r0, _080AC7F4 @ =0x8005CD73
	cmp r1, r0
	bne _080AC7EC
	b _080ACBE0
_080AC7EC:
	b _080ACD64
	.byte 0x00, 0x00
_080AC7F0: .4byte 0x8005A569
_080AC7F4: .4byte 0x8005CD73
_080AC7F8:
	ldr r0, _080AC820 @ =0xC6519465
	cmp r1, r0
	bne _080AC800
	b _080ACBE8
_080AC800:
	cmp r1, r0
	bhi _080AC87C
	ldr r0, _080AC824 @ =0xC290A429
	cmp r1, r0
	bne _080AC80C
	b _080ACBE8
_080AC80C:
	cmp r1, r0
	bhi _080AC844
	ldr r0, _080AC828 @ =0xC0B02C0B
	cmp r1, r0
	bne _080AC818
	b _080ACBE8
_080AC818:
	cmp r1, r0
	bhi _080AC830
	ldr r0, _080AC82C @ =0xC0100401
	b _080AC8AE
_080AC820: .4byte 0xC6519465
_080AC824: .4byte 0xC290A429
_080AC828: .4byte 0xC0B02C0B
_080AC82C: .4byte 0xC0100401
_080AC830:
	ldr r0, _080AC83C @ =0xC1505415
	cmp r1, r0
	bne _080AC838
	b _080ACBE8
_080AC838:
	ldr r0, _080AC840 @ =0xC1F07C1F
	b _080AC8AE
_080AC83C: .4byte 0xC1505415
_080AC840: .4byte 0xC1F07C1F
_080AC844:
	ldr r0, _080AC85C @ =0xC4711C47
	cmp r1, r0
	bne _080AC84C
	b _080ACBE8
_080AC84C:
	cmp r1, r0
	bhi _080AC868
	ldr r0, _080AC860 @ =0xC330CC33
	cmp r1, r0
	bne _080AC858
	b _080ACBE8
_080AC858:
	ldr r0, _080AC864 @ =0xC3D0F43D
	b _080AC8AE
_080AC85C: .4byte 0xC4711C47
_080AC860: .4byte 0xC330CC33
_080AC864: .4byte 0xC3D0F43D
_080AC868:
	ldr r0, _080AC874 @ =0xC5114451
	cmp r1, r0
	bne _080AC870
	b _080ACBE8
_080AC870:
	ldr r0, _080AC878 @ =0xC5B16C5B
	b _080AC8AE
_080AC874: .4byte 0xC5114451
_080AC878: .4byte 0xC5B16C5B
_080AC87C:
	ldr r0, _080AC898 @ =0xC9725C97
	cmp r1, r0
	bne _080AC884
	b _080ACBE8
_080AC884:
	cmp r1, r0
	bhi _080AC8C0
	ldr r0, _080AC89C @ =0xC791E479
	cmp r1, r0
	bne _080AC890
	b _080ACBE8
_080AC890:
	cmp r1, r0
	bhi _080AC8A4
	ldr r0, _080AC8A0 @ =0xC6F1BC6F
	b _080AC8AE
_080AC898: .4byte 0xC9725C97
_080AC89C: .4byte 0xC791E479
_080AC8A0: .4byte 0xC6F1BC6F
_080AC8A4:
	ldr r0, _080AC8B8 @ =0xC8320C83
	cmp r1, r0
	bne _080AC8AC
	b _080ACBE8
_080AC8AC:
	ldr r0, _080AC8BC @ =0xC8D2348D
_080AC8AE:
	cmp r1, r0
	bne _080AC8B4
	b _080ACBE8
_080AC8B4:
	b _080ACD64
	.byte 0x00, 0x00
_080AC8B8: .4byte 0xC8320C83
_080AC8BC: .4byte 0xC8D2348D
_080AC8C0:
	ldr r0, _080AC8E0 @ =0xCAB2AD37
	cmp r1, r0
	bne _080AC8C8
	b _080ACCB0
_080AC8C8:
	cmp r1, r0
	bhi _080AC8EC
	ldr r0, _080AC8E4 @ =0xCA1284A1
	cmp r1, r0
	bne _080AC8D4
	b _080ACBE8
_080AC8D4:
	ldr r0, _080AC8E8 @ =0xCAB2ACAB
	cmp r1, r0
	bne _080AC8DC
	b _080ACC28
_080AC8DC:
	b _080ACD64
	.byte 0x00, 0x00
_080AC8E0: .4byte 0xCAB2AD37
_080AC8E4: .4byte 0xCA1284A1
_080AC8E8: .4byte 0xCAB2ACAB
_080AC8EC:
	ldr r0, _080AC900 @ =0xCB52D4B5
	cmp r1, r0
	bne _080AC8F4
	b _080ACC2C
_080AC8F4:
	ldr r0, _080AC904 @ =0xCBF2FCBF
	cmp r1, r0
	bne _080AC8FC
	b _080ACC30
_080AC8FC:
	b _080ACD64
	.byte 0x00, 0x00
_080AC900: .4byte 0xCB52D4B5
_080AC904: .4byte 0xCBF2FCBF
_080AC908:
	ldr r0, _080AC944 @ =0xE95A5695
	cmp r1, r0
	bne _080AC910
	b _080ACCD0
_080AC910:
	cmp r1, r0
	bls _080AC916
	b _080ACA4C
_080AC916:
	ldr r0, _080AC948 @ =0xD0F43D0F
	cmp r1, r0
	bne _080AC91E
	b _080ACC50
_080AC91E:
	cmp r1, r0
	bhi _080AC9B8
	ldr r0, _080AC94C @ =0xCE734CDD
	cmp r1, r0
	bne _080AC92A
	b _080ACC90
_080AC92A:
	cmp r1, r0
	bhi _080AC974
	ldr r0, _080AC950 @ =0xCDD374DD
	cmp r1, r0
	bne _080AC936
	b _080ACC3C
_080AC936:
	cmp r1, r0
	bhi _080AC958
	ldr r0, _080AC954 @ =0xCD334CD3
	cmp r1, r0
	bne _080AC942
	b _080ACC38
_080AC942:
	b _080ACD64
_080AC944: .4byte 0xE95A5695
_080AC948: .4byte 0xD0F43D0F
_080AC94C: .4byte 0xCE734CDD
_080AC950: .4byte 0xCDD374DD
_080AC954: .4byte 0xCD334CD3
_080AC958:
	ldr r0, _080AC96C @ =0xCE72ACB5
	cmp r1, r0
	bne _080AC960
	b _080ACCA0
_080AC960:
	ldr r0, _080AC970 @ =0xCE734CC9
	cmp r1, r0
	bne _080AC968
	b _080ACCC0
_080AC968:
	b _080ACD64
	.byte 0x00, 0x00
_080AC96C: .4byte 0xCE72ACB5
_080AC970: .4byte 0xCE734CC9
_080AC974:
	ldr r0, _080AC994 @ =0xCF13C4F1
	cmp r1, r0
	bne _080AC97C
	b _080ACC48
_080AC97C:
	cmp r1, r0
	bhi _080AC99C
	ldr r0, _080AC998 @ =0xCE739CDD
	cmp r1, r0
	bne _080AC988
	b _080ACC80
_080AC988:
	adds r0, #0x0A
	cmp r1, r0
	bne _080AC990
	b _080ACC40
_080AC990:
	b _080ACD64
	.byte 0x00, 0x00
_080AC994: .4byte 0xCF13C4F1
_080AC998: .4byte 0xCE739CDD
_080AC99C:
	ldr r0, _080AC9B0 @ =0xCFB3ECFB
	cmp r1, r0
	bne _080AC9A4
	b _080ACC44
_080AC9A4:
	ldr r0, _080AC9B4 @ =0xD0541505
	cmp r1, r0
	bne _080AC9AC
	b _080ACC4C
_080AC9AC:
	b _080ACD64
	.byte 0x00, 0x00
_080AC9B0: .4byte 0xCFB3ECFB
_080AC9B4: .4byte 0xD0541505
_080AC9B8:
	ldr r0, _080AC9DC @ =0xD4150541
	cmp r1, r0
	bne _080AC9C0
	b _080ACC64
_080AC9C0:
	cmp r1, r0
	bhi _080ACA04
	ldr r0, _080AC9E0 @ =0xD2348D23
	cmp r1, r0
	bne _080AC9CC
	b _080ACC58
_080AC9CC:
	cmp r1, r0
	bhi _080AC9E8
	ldr r0, _080AC9E4 @ =0xD1946519
	cmp r1, r0
	bne _080AC9D8
	b _080ACC54
_080AC9D8:
	b _080ACD64
	.byte 0x00, 0x00
_080AC9DC: .4byte 0xD4150541
_080AC9E0: .4byte 0xD2348D23
_080AC9E4: .4byte 0xD1946519
_080AC9E8:
	ldr r0, _080AC9FC @ =0xD2D4B52D
	cmp r1, r0
	bne _080AC9F0
	b _080ACC5C
_080AC9F0:
	ldr r0, _080ACA00 @ =0xD374DD37
	cmp r1, r0
	bne _080AC9F8
	b _080ACC60
_080AC9F8:
	b _080ACD64
	.byte 0x00, 0x00
_080AC9FC: .4byte 0xD2D4B52D
_080ACA00: .4byte 0xD374DD37
_080ACA04:
	ldr r0, _080ACA24 @ =0xD5F57D5F
	cmp r1, r0
	bne _080ACA0C
	b _080ACC70
_080ACA0C:
	cmp r1, r0
	bhi _080ACA30
	ldr r0, _080ACA28 @ =0xD4B52D4B
	cmp r1, r0
	bne _080ACA18
	b _080ACC68
_080ACA18:
	ldr r0, _080ACA2C @ =0xD5555555
	cmp r1, r0
	bne _080ACA20
	b _080ACC6C
_080ACA20:
	b _080ACD64
	.byte 0x00, 0x00
_080ACA24: .4byte 0xD5F57D5F
_080ACA28: .4byte 0xD4B52D4B
_080ACA2C: .4byte 0xD5555555
_080ACA30:
	ldr r0, _080ACA44 @ =0xD695A569
	cmp r1, r0
	bne _080ACA38
	b _080ACC74
_080ACA38:
	ldr r0, _080ACA48 @ =0xD735CD73
	cmp r1, r0
	bne _080ACA40
	b _080ACC78
_080ACA40:
	b _080ACD64
	.byte 0x00, 0x00
_080ACA44: .4byte 0xD695A569
_080ACA48: .4byte 0xD735CD73
_080ACA4C:
	ldr r0, _080ACA7C @ =0xF21CAF21
	cmp r1, r0
	bne _080ACA54
	b _080ACD48
_080ACA54:
	cmp r1, r0
	bhi _080ACAF0
	ldr r0, _080ACA80 @ =0xED1B1EC7
	cmp r1, r0
	bne _080ACA60
	b _080ACD2C
_080ACA60:
	cmp r1, r0
	bhi _080ACAA8
	ldr r0, _080ACA84 @ =0xEB3AA6B3
	cmp r1, r0
	bne _080ACA6C
	b _080ACD18
_080ACA6C:
	cmp r1, r0
	bhi _080ACA8C
	ldr r0, _080ACA88 @ =0xE9FA7E9F
	cmp r1, r0
	bne _080ACA78
	b _080ACC7C
_080ACA78:
	b _080ACD64
	.byte 0x00, 0x00
_080ACA7C: .4byte 0xF21CAF21
_080ACA80: .4byte 0xED1B1EC7
_080ACA84: .4byte 0xEB3AA6B3
_080ACA88: .4byte 0xE9FA7E9F
_080ACA8C:
	ldr r0, _080ACAA0 @ =0xEB3ACEB3
	cmp r1, r0
	bne _080ACA94
	b _080ACD14
_080ACA94:
	ldr r0, _080ACAA4 @ =0xED1AF6BD
	cmp r1, r0
	bne _080ACA9C
	b _080ACD28
_080ACA9C:
	b _080ACD64
	.byte 0x00, 0x00
_080ACAA0: .4byte 0xEB3ACEB3
_080ACAA4: .4byte 0xED1AF6BD
_080ACAA8:
	ldr r0, _080ACAC8 @ =0xF0DBE6F9
	cmp r1, r0
	bne _080ACAB0
	b _080ACD30
_080ACAB0:
	cmp r1, r0
	bhi _080ACAD4
	ldr r0, _080ACACC @ =0xEE5B96E5
	cmp r1, r0
	bne _080ACABC
	b _080ACD1C
_080ACABC:
	ldr r0, _080ACAD0 @ =0xEEFB96EF
	cmp r1, r0
	bne _080ACAC4
	b _080ACD20
_080ACAC4:
	b _080ACD64
	.byte 0x00, 0x00
_080ACAC8: .4byte 0xF0DBE6F9
_080ACACC: .4byte 0xEE5B96E5
_080ACAD0: .4byte 0xEEFB96EF
_080ACAD4:
	ldr r0, _080ACAE8 @ =0xF17C0F03
	cmp r1, r0
	bne _080ACADC
	b _080ACD40
_080ACADC:
	ldr r0, _080ACAEC @ =0xF21C8721
	cmp r1, r0
	bne _080ACAE4
	b _080ACD10
_080ACAE4:
	b _080ACD64
	.byte 0x00, 0x00
_080ACAE8: .4byte 0xF17C0F03
_080ACAEC: .4byte 0xF21C8721
_080ACAF0:
	ldr r0, _080ACB1C @ =0xF5DD4F53
	cmp r1, r0
	bne _080ACAF8
	b _080ACD3C
_080ACAF8:
	cmp r1, r0
	bhi _080ACB48
	ldr r0, _080ACB20 @ =0xF53D4F53
	cmp r1, r0
	bne _080ACB04
	b _080ACD60
_080ACB04:
	cmp r1, r0
	bhi _080ACB2C
	ldr r0, _080ACB24 @ =0xF35CFF3F
	cmp r1, r0
	bne _080ACB10
	b _080ACD44
_080ACB10:
	ldr r0, _080ACB28 @ =0xF49D2735
	cmp r1, r0
	bne _080ACB18
	b _080ACD24
_080ACB18:
	b _080ACD64
	.byte 0x00, 0x00
_080ACB1C: .4byte 0xF5DD4F53
_080ACB20: .4byte 0xF53D4F53
_080ACB24: .4byte 0xF35CFF3F
_080ACB28: .4byte 0xF49D2735
_080ACB2C:
	ldr r0, _080ACB40 @ =0xF53D4F5D
	cmp r1, r0
	bne _080ACB34
	b _080ACD38
_080ACB34:
	ldr r0, _080ACB44 @ =0xF53D7753
	cmp r1, r0
	bne _080ACB3C
	b _080ACD34
_080ACB3C:
	b _080ACD64
	.byte 0x00, 0x00
_080ACB40: .4byte 0xF53D4F5D
_080ACB44: .4byte 0xF53D7753
_080ACB48:
	ldr r0, _080ACB68 @ =0xF85E3F85
	cmp r1, r0
	bne _080ACB50
	b _080ACD5C
_080ACB50:
	cmp r1, r0
	bhi _080ACB74
	ldr r0, _080ACB6C @ =0xF71D9F71
	cmp r1, r0
	bne _080ACB5C
	b _080ACD4C
_080ACB5C:
	ldr r0, _080ACB70 @ =0xF7BDC767
	cmp r1, r0
	bne _080ACB64
	b _080ACD50
_080ACB64:
	b _080ACD64
	.byte 0x00, 0x00
_080ACB68: .4byte 0xF85E3F85
_080ACB6C: .4byte 0xF71D9F71
_080ACB70: .4byte 0xF7BDC767
_080ACB74:
	ldr r0, _080ACB88 @ =0xFA3EB7A3
	cmp r1, r0
	bne _080ACB7C
	b _080ACD58
_080ACB7C:
	ldr r0, _080ACB8C @ =0xFADEB7A3
	cmp r1, r0
	bne _080ACB84
	b _080ACD54
_080ACB84:
	b _080ACD64
	.byte 0x00, 0x00
_080ACB88: .4byte 0xFA3EB7A3
_080ACB8C: .4byte 0xFADEB7A3
_080ACB90:
	movs r0, #0x00
	b _080AD136
_080ACB94:
	movs r0, #0x02
	b _080AD136
_080ACB98:
	movs r0, #0x01
	b _080AD136
_080ACB9C:
	movs r0, #0x03
	b _080AD136
_080ACBA0:
	movs r0, #0x0B
	b _080AD136
_080ACBA4:
	movs r0, #0x04
	b _080AD136
_080ACBA8:
	movs r0, #0x2C
	b _080AD136
_080ACBAC:
	movs r0, #0x0F
	b _080AD136
_080ACBB0:
	movs r0, #0x11
	b _080AD136
_080ACBB4:
	movs r0, #0x13
	b _080AD136
_080ACBB8:
	movs r0, #0x15
	b _080AD136
_080ACBBC:
	movs r0, #0x17
	b _080AD136
_080ACBC0:
	movs r0, #0x19
	b _080AD136
_080ACBC4:
	movs r0, #0x1B
	b _080AD136
_080ACBC8:
	movs r0, #0x1D
	b _080AD136
_080ACBCC:
	movs r0, #0x1F
	b _080AD136
_080ACBD0:
	movs r0, #0x21
	b _080AD136
_080ACBD4:
	movs r0, #0x23
	b _080AD136
_080ACBD8:
	movs r0, #0x25
	b _080AD136
_080ACBDC:
	movs r0, #0x27
	b _080AD136
_080ACBE0:
	movs r0, #0x29
	b _080AD136
_080ACBE4:
	movs r0, #0x2B
	b _080AD136
_080ACBE8:
	adds r0, r6, #0x0
	subs r0, #0x0A
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bhi _080ACC06
	movs r0, #0x00
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACC06
	movs r0, #0x32
	str r0, [r7, #0x00]
	b _080AD136
_080ACC06:
	adds r0, r6, #0x0
	subs r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bls _080ACC14
	b _080ACD64
_080ACC14:
	movs r0, #0x02
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080ACC22
	b _080ACD64
_080ACC22:
	movs r0, #0x33
	str r0, [r7, #0x00]
	b _080AD136
_080ACC28:
	movs r0, #0x07
	b _080AD136
_080ACC2C:
	movs r0, #0x08
	b _080AD136
_080ACC30:
	movs r0, #0x09
	b _080AD136
_080ACC34:
	movs r0, #0x0A
	b _080AD136
_080ACC38:
	movs r0, #0x0C
	b _080AD136
_080ACC3C:
	movs r0, #0x0D
	b _080AD136
_080ACC40:
	movs r0, #0x2D
	b _080AD136
_080ACC44:
	movs r0, #0x0E
	b _080AD136
_080ACC48:
	movs r0, #0x10
	b _080AD136
_080ACC4C:
	movs r0, #0x12
	b _080AD136
_080ACC50:
	movs r0, #0x14
	b _080AD136
_080ACC54:
	movs r0, #0x16
	b _080AD136
_080ACC58:
	movs r0, #0x18
	b _080AD136
_080ACC5C:
	movs r0, #0x1A
	b _080AD136
_080ACC60:
	movs r0, #0x1C
	b _080AD136
_080ACC64:
	movs r0, #0x1E
	b _080AD136
_080ACC68:
	movs r0, #0x20
	b _080AD136
_080ACC6C:
	movs r0, #0x22
	b _080AD136
_080ACC70:
	movs r0, #0x24
	b _080AD136
_080ACC74:
	movs r0, #0x26
	b _080AD136
_080ACC78:
	movs r0, #0x28
	b _080AD136
_080ACC7C:
	movs r0, #0x2A
	b _080AD136
_080ACC80:
	movs r0, #0x27
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD64
	movs r0, #0x35
	b _080AD136
_080ACC90:
	movs r0, #0x26
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD64
	movs r0, #0x36
	b _080AD136
_080ACCA0:
	movs r0, #0x22
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD64
	movs r0, #0x41
	b _080AD136
_080ACCB0:
	movs r0, #0x20
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD64
	movs r0, #0x46
	b _080AD136
_080ACCC0:
	movs r0, #0x2B
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD64
	movs r0, #0x4D
	b _080AD136
_080ACCD0:
	ldr r0, _080ACCF4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _080ACD64
	subs r0, r6, #0x5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x0A
	bhi _080ACCF8
	movs r0, #0x52
	b _080AD136
_080ACCF4: .4byte 0x02039B84
_080ACCF8:
	adds r0, r6, #0x0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bhi _080ACD08
	movs r0, #0x53
	b _080AD136
_080ACD08:
	cmp r6, #0x1A
	bls _080ACD64
	movs r0, #0x54
	b _080AD136
_080ACD10:
	movs r0, #0x55
	b _080AD136
_080ACD14:
	movs r0, #0x56
	b _080AD136
_080ACD18:
	movs r0, #0x57
	b _080AD136
_080ACD1C:
	movs r0, #0x58
	b _080AD136
_080ACD20:
	movs r0, #0x59
	b _080AD136
_080ACD24:
	movs r0, #0x5A
	b _080AD136
_080ACD28:
	movs r0, #0x5B
	b _080AD136
_080ACD2C:
	movs r0, #0x5C
	b _080AD136
_080ACD30:
	movs r0, #0x5D
	b _080AD136
_080ACD34:
	movs r0, #0x5E
	b _080AD136
_080ACD38:
	movs r0, #0x5F
	b _080AD136
_080ACD3C:
	movs r0, #0x60
	b _080AD136
_080ACD40:
	movs r0, #0x61
	b _080AD136
_080ACD44:
	movs r0, #0x62
	b _080AD136
_080ACD48:
	movs r0, #0x63
	b _080AD136
_080ACD4C:
	movs r0, #0x64
	b _080AD136
_080ACD50:
	movs r0, #0x65
	b _080AD136
_080ACD54:
	movs r0, #0x66
	b _080AD136
_080ACD58:
	movs r0, #0x67
	b _080AD136
_080ACD5C:
	movs r0, #0x68
	b _080AD136
_080ACD60:
	movs r0, #0x69
	b _080AD136
_080ACD64:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x2B
	bl func_080ADF94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080ACD82
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADFD4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD92
_080ACD82:
	movs r0, #0x2A
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACD92
	movs r0, #0x37
	b _080AD136
_080ACD92:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE080
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACDB0
	movs r0, #0x29
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACDB0
	movs r0, #0x38
	b _080AD136
_080ACDB0:
	adds r0, r5, #0x0
	movs r1, #0x17
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACDD0
	movs r0, #0x1B
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACDD0
	movs r0, #0x3A
	b _080AD136
_080ACDD0:
	adds r0, r5, #0x0
	movs r1, #0x18
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACDF0
	movs r0, #0x1C
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACDF0
	movs r0, #0x3B
	b _080AD136
_080ACDF0:
	adds r0, r5, #0x0
	movs r1, #0x1F
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE10
	movs r0, #0x1D
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE10
	movs r0, #0x3C
	b _080AD136
_080ACE10:
	adds r0, r5, #0x0
	movs r1, #0x12
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE30
	movs r0, #0x17
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE30
	movs r0, #0x3D
	b _080AD136
_080ACE30:
	adds r0, r5, #0x0
	movs r1, #0x13
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE50
	movs r0, #0x18
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE50
	movs r0, #0x3E
	b _080AD136
_080ACE50:
	adds r0, r5, #0x0
	movs r1, #0x14
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE70
	movs r0, #0x19
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE70
	movs r0, #0x3F
	b _080AD136
_080ACE70:
	adds r0, r5, #0x0
	movs r1, #0x16
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE90
	movs r0, #0x1A
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACE90
	movs r0, #0x40
	b _080AD136
_080ACE90:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE0B4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACEAE
	movs r0, #0x2E
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACEAE
	movs r0, #0x42
	b _080AD136
_080ACEAE:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE0F4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACECC
	movs r0, #0x3A
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACECC
	movs r0, #0x43
	b _080AD136
_080ACECC:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE014
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACEEA
	movs r0, #0x2C
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACEEA
	movs r0, #0x45
	b _080AD136
_080ACEEA:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADF60
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF08
	movs r0, #0x1F
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF08
	movs r0, #0x47
	b _080AD136
_080ACF08:
	adds r0, r5, #0x0
	movs r1, #0x19
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_080ADEEC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF2A
	movs r0, #0x23
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF2A
	movs r0, #0x48
	b _080AD136
_080ACF2A:
	adds r0, r5, #0x0
	movs r1, #0x1B
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_080ADEEC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF4C
	movs r0, #0x32
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF4C
	movs r0, #0x49
	b _080AD136
_080ACF4C:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE134
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF6A
	movs r0, #0x38
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF6A
	movs r0, #0x4A
	b _080AD136
_080ACF6A:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE168
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF88
	movs r0, #0x1E
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACF88
	movs r0, #0x4B
	b _080AD136
_080ACF88:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE1A8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACFA6
	movs r0, #0x21
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACFA6
	movs r0, #0x4C
	b _080AD136
_080ACFA6:
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x16
	movs r3, #0x17
	bl func_080ADE2C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACFCC
	movs r0, #0x28
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACFCC
	movs r0, #0x4E
	b _080AD136
_080ACFCC:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x18
	movs r3, #0x16
	bl func_080ADE78
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACFEE
	movs r0, #0x24
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ACFEE
	movs r0, #0x4F
	b _080AD136
_080ACFEE:
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x16
	movs r3, #0x19
	bl func_080ADE2C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD014
	movs r0, #0x25
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD014
	movs r0, #0x50
	b _080AD136
_080AD014:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE1E8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD032
	movs r0, #0x2D
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD032
	movs r0, #0x51
	b _080AD136
_080AD032:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADD04
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD07C
	adds r0, r6, #0x0
	subs r0, #0x0A
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bhi _080AD05E
	movs r0, #0x01
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD05E
	movs r0, #0x2E
	str r0, [r7, #0x00]
	b _080AD136
_080AD05E:
	adds r0, r6, #0x0
	subs r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bhi _080AD07C
	movs r0, #0x05
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD07C
	movs r0, #0x05
	str r0, [r7, #0x00]
	b _080AD136
_080AD07C:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADD58
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD0FA
	subs r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bhi _080AD0A6
	movs r0, #0x06
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD0A6
	movs r0, #0x2F
	str r0, [r7, #0x00]
	b _080AD136
_080AD0A6:
	adds r0, r6, #0x0
	subs r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bhi _080AD0C4
	movs r0, #0x04
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD0C4
	movs r0, #0x06
	str r0, [r7, #0x00]
	b _080AD136
_080AD0C4:
	subs r0, r6, #0x7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bhi _080AD0E0
	movs r0, #0x07
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD0E0
	movs r0, #0x30
	str r0, [r7, #0x00]
	b _080AD136
_080AD0E0:
	cmp r6, #0x00
	beq _080AD0E8
	cmp r6, #0x1B
	bne _080AD0FA
_080AD0E8:
	movs r0, #0x03
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD0FA
	movs r0, #0x34
	str r0, [r7, #0x00]
	b _080AD136
_080AD0FA:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADDA8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD11A
	movs r0, #0x08
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD11A
	movs r0, #0x31
	str r0, [r7, #0x00]
	b _080AD136
_080AD11A:
	ldr r0, [sp, #0x028]
	mov r1, r8
	strb r1, [r0, #0x00]
	mov r3, r8
	cmp r3, #0x00
	bne _080AD12A
	movs r0, #0x6A
	b _080AD136
_080AD12A:
	mov r0, r8
	cmp r0, #0x01
	beq _080AD134
	movs r0, #0x6B
	b _080AD136
_080AD134:
	ldr r0, [r7, #0x00]
_080AD136:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
